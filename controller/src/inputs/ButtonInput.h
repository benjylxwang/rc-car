#ifndef BUTTON_INPUT_H
#define BUTTON_INPUT_H

#include <Arduino.h>

class ButtonInput
{
public:
    ButtonInput(byte pin_, byte inputType_ = INPUT, bool invert_ = false)
    {
        pin = pin_;
        inputType = inputType_;
        invert = invert_;
    }

    void setup();
    bool get();
private:
    byte pin;

    // Settings
    byte inputType;
    bool invert;
};

#endif