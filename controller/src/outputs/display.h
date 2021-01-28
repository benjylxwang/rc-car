#ifndef DISPLAY_H
#define DISPLAY_H

#include <LiquidCrystal_I2C.h>
#include "../state.h"

class Display
{
public:
    Display();

    void setup();
    void printState(State state);
private:
    // Display
    LiquidCrystal_I2C lcd;
    unsigned long lastPrint;

    void printLightInfo(State state);
};

#endif