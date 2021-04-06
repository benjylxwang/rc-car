#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>
#include "../state.h"

class Motor
{
public:
    Motor(byte enablePin, byte inAPin, byte inBPin);

    void setup();
    void update(State state);

private:
    byte enable;
    byte inA;
    byte inB;

    void setMotorSpeed(int speed);
};

#endif