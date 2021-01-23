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

void Sender::send(Input& input)
{
    // Format input object as protocol payload and send
    char data[10] = {0};

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
}