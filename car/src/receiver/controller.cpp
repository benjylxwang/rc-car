#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#include "controller.h"

Controller::Controller(byte cePin_, byte csPin_)
{
    cePin = cePin_;
    csnPin = csPin_;
}

void Controller::setup()
{
    radio.init(RF_CAR_ID, cePin, csnPin);
}

void Controller::update(State &state)
{
    if (radio.hasData())
    {
        char data[32] = {0};
        radio.readData(&data);

        // Wipe previous usersignal
        if (state.userSignal)
            free(state.userSignal);
        state.userSignal = (Signal *)calloc(1, sizeof(Signal));

        // === Process data === Change stuff here if changing protocol
        // Steering data
        int16_t *steering = (int16_t *)&data[0];
        state.userSignal->forwardsMotion = *steering;
        steering++;
        state.userSignal->rightMotion = *steering;

        // Lights data
        int8_t *indicators = (int8_t *)&data[4];
        state.userSignal->indicator = (*indicators == 0) ? off : (*indicators < 0) ? left
                                                                                   : right;
        // Headlights
        bool *b = (bool *)&data[5];
        state.userSignal->toggleAutoLights = *b;
        b++;
        state.userSignal->headlightsOn = *b;

        // Hazard lights
        b++;
        state.userSignal->hazard = *b;

        // Beeper
        b++;
        state.userSignal->beep = *b;

        #if VERBOSE
        Serial.print("Motion: (");
        Serial.print(state.userSignal->forwardsMotion);
        Serial.print(", ");
        Serial.print(state.userSignal->rightMotion);
        Serial.print(") Indicator: ");
        Serial.print(state.userSignal->indicator);
        Serial.print(" Auto Lights: ");
        Serial.print(state.userSignal->toggleAutoLights);
        Serial.print(" Headlights: ");
        Serial.print(state.userSignal->headlightsOn);
        Serial.print(" Hazard: ");
        Serial.print(state.userSignal->hazard);
        Serial.print(" Beep: ");
        Serial.print(state.userSignal->beep);
        Serial.println();
        #endif
    }
}