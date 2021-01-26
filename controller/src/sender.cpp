#include "sender.h"
#include "../constants.h"

#include <SPI.h>
#include <NRFLite.h>

Sender::Sender(byte cePin_, byte csPin_)
{
    cePin = cePin_;
    csnPin = csPin_;
}

void Sender::setup()
{
    radio.init(RF_CONTROLLER_ID, cePin, csnPin);
}

void Sender::send(Input& input, State& carState)
{
    // Format input object as protocol payload and send
    char data[32] = {0};

    // Throttle and turning (int16_t)
    int16_t* i16 = (int16_t*) &data[0];
    *i16 = input.throttle;
    i16++;
    *i16 = input.turning;

    // Indicators
    int8_t* i8 = (int8_t*) &data[4];
    *i8 = input.indication;

    // Lights and Beep
    bool* b = (bool*) &data[5];
    *b = input.toggleAutoHeadlights;
    b++;
    *b = input.toggleHeadlights;
    b++;
    *b = input.toggleHazardlights;
    b++;
    *b = input.beepHorn;

    // Send payload
    radio.send(RF_CAR_ID, &data, sizeof(data));

    // Check for sensor data in ack
    if (radio.hasAckData()) {
        char ackData[32] = {0};
        // Get sensor data from ack
        radio.readData(&ackData);
        Serial.println("Received ack data!");

        // Parse data into sensor state object
        // Speed and turning angle
        float* f = (float*) &ackData[0];
        carState.speed = *f++;
        carState.turningAngle = *f++;

        // Indicators
        int8_t* i8 = (int8_t*) &ackData[8];
        carState.indicators = *i8;

        // Lights
        bool* b = (bool*) &ackData[9];
        carState.isLightAutomatic = *b++;
        carState.isHeadlightsOn = *b++;
        carState.isHazardsOn = *b++;

        // Temp and Humidity
        f = (float*) &ackData[12];
        carState.temperature = *f++;
        carState.humidity = *f++;

        // Horn
        b = (bool*) &ackData[20];
        carState.isHornOn = *b;
    }
}