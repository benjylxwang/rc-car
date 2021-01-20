#ifndef SPEEDOMETER_H
#define SPEEDOMETER_H

#include <Arduino.h>
#include "../state.h"

class Speedometer
{
public:
    Speedometer(byte digit1, byte digit2, byte digit3, byte digit4, byte latchPin, byte clockPin, byte dataPin);

    void setup();
    void update(State state);
private:
    // Pins
    byte digits[4];
    byte latch;
    byte clock;
    byte data;

    void choosePin(byte pin);
    void writeData(int value);
    int digitToHex(byte digit);
};

#endif