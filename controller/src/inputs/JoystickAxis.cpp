#include "JoystickAxis.h"

#include <Arduino.h>

JoystickAxis::JoystickAxis(byte pin_)
{
    pin = pin_;
}

void JoystickAxis::setup()
{
    pinMode(pin, INPUT);
}

int16_t JoystickAxis::get()
{
    return map(analogRead(pin), 0, 1024, -512, 512);
}