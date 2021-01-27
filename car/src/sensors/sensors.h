#ifndef SENSORS_H
#define SENSORS_H

#include "../state.h"

class Sensors
{
public:
    Sensors(byte photoResistorPin);

    void setup();
    void update(State& state);
private:
    byte photoResistorPin;
    unsigned long darknessBeginning;
};

#endif