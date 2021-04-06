#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <Arduino.h>
#include "../state.h"
#include "../../constants.h"
#include <NRFLite.h>

class Controller
{
public:
    Controller(byte cePin, byte csPin);

    void setup();
    void update(State& state);

private:
    NRFLite radio;

    // Pins
    byte cePin;
    byte csnPin;

    void parseData(State& state);
    void prepareAck(State& state);

};

#endif