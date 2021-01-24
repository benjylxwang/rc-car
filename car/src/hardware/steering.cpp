#include "steering.h"
#include "../../constants.h"

Steering::Steering(byte pin_)
{
    pin = pin_;
}

void Steering::setup()
{
    servo.attach(pin);
}

void Steering::update(State state)
{
    if (state.userSignal)
    {
        int16_t input = state.userSignal->rightMotion;

        servo.write(map(input, -512, 512, 0, 180));
    }
}
