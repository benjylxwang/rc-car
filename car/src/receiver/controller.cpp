#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#include "controller.h"

Controller::Controller(byte cePin, byte csPin) : receiver(cePin, csPin)
{
}

void Controller::setup()
{
    receiver.begin();
    receiver.openReadingPipe(0, (uint8_t*) CONTROLLER_RECEIVE_ADDRESS);
    receiver.startListening();
}
void Controller::update(State &state)
{
    if (receiver.available())
    {
        char data[32] = {0};
        receiver.read(&data, sizeof(data));

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
    }
}