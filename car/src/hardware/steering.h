#ifndef STEERING_H
#define STEERING_H

#include <Arduino.h>
#include <Servo.h>
#include "../state.h"

class Steering
{
public:
    Steering(byte pin);
    void setup();
    void update(State state);

private:
    byte pin;
    Servo servo;
};

#endif