#ifndef JOYSTICK_AXIS_H
#define JOYSTICK_AXIS_H

#include <stdint.h>
#include <Arduino.h>

class JoystickAxis {
public:
    JoystickAxis(byte pin);

    void setup();
    int16_t get();

private: 
    byte pin;
};

#endif