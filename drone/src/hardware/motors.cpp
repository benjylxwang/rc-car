#include "motors.h"

Motors::Motors(byte frontLeftPin,
               byte frontRightPin,
               byte backLeftPin,
               byte backRightPin)
{
    pins[MOTOR_FRONT_LEFT] = frontLeftPin;
    pins[MOTOR_FRONT_RIGHT] = frontRightPin;
    pins[MOTOR_BACK_LEFT] = backLeftPin;
    pins[MOTOR_BACK_RIGHT] = backRightPin;
}

void Motors::setup()
{
    for (int i = 0; i < MOTOR_COUNT; i++) {
        pinMode(pins[i], OUTPUT);
    }
}

void Motors::run(State state)
{
}