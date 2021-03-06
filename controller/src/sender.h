#ifndef SENDER_H
#define SENDER_H

#include "input.h"
#include "state.h"
#include "../constants.h"
#include <NRFLite.h>

class Sender {
public:
    Sender(byte cePin, byte csPin);

    void setup();
    void send(Input& input, State& carState);

private:
    NRFLite radio;

    // Pins
    byte cePin;
    byte csnPin;
};

#endif