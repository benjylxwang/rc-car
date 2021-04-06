#include "motor.h"

#include "../../constants.h"

Motor::Motor(byte enablePin, byte inAPin, byte inBPin)
{
    enable = enablePin;
    inA = inAPin;
    inB = inBPin;
}

void Motor::setup()
{
    pinMode(enable, OUTPUT);
    pinMode(inA, OUTPUT);
    pinMode(inB, OUTPUT);

    setMotorSpeed(0);
}
void Motor::update(State state)
{
    if (state.userSignal)
    {
        int16_t input = state.userSignal->forwardsMotion;
        setMotorSpeed(map(input, -CONTROLLER_ANALOG_MAX_VALUE, CONTROLLER_ANALOG_MAX_VALUE, -MOTOR_MAX_SPEED, MOTOR_MAX_SPEED));
    }
}

void Motor::setMotorSpeed(int speed)
{
    if (speed > 0)
    {
        // Forwards
        digitalWrite(inA, HIGH);
        digitalWrite(inB, LOW);
        // PWM output
        analogWrite(enable, abs(speed));
    }
    else if (speed < 0)
    {
        // Backwards
        digitalWrite(inA, LOW);
        digitalWrite(inB, HIGH);
        // PWM output
        analogWrite(enable, abs(speed));
    } else {
        // 0
        digitalWrite(inA, LOW);
        digitalWrite(inB, LOW);
        digitalWrite(enable, LOW);
    }

}