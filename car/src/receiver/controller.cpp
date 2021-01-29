#include "controller.h"
#include <Arduino.h>

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
    // Wipe previous usersignal
    if (state.userSignal)
        free(state.userSignal);

    // Prepare ack - will be sent back if radio data is received
    prepareAck(state);
    
    // If we have data, fill, otherwise, set state usersignal to null
    if (radio.hasData())
    {
        parseData(state);
    }
    else
    {
        state.userSignal = nullptr;
    }
}

void Controller::parseData(State &state)
{
    char data[32] = {0};
    radio.readData(&data);
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
    Serial.print(" T: ");
    Serial.print(state.temperature);
    Serial.print(" H: ");
    Serial.print(state.humidity);
    Serial.println();
#endif
}

void Controller::prepareAck(State& state) {
    char data[32] = {0};

    // Fill data structure according to protocol
    // Speed and turning angle
    float* f = (float*) &data[0];
    *f = state.speed;
    int8_t *i8 = (int8_t *)&data[4];
    *i8 = state.turningAngle;

    // Indicators
    i8 = (int8_t *) &data[8];
    *i8 = state.indicators;

    // Light data
    byte* b = (byte*) &data[9];
    *b = state.isLightAutomatic;
    b++;
    *b = state.isHeadlightsOn;
    b++;
    *b = state.isHazardsOn;

    // Temperature and Humidity
    f = (float*) &data[12];
    *f = state.temperature;
    f++;
    *f = state.humidity;

    // Beep state
    b = (byte*) &data[20];
    *b = state.isHornOn;

    // Add new ack data to pipeline and remove any old data in the pipeline
    radio.addAckData(data, 32, true);
}