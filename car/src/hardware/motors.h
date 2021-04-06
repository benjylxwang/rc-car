#ifndef MOTORS_H
#define MOTORS_H

#include <Arduino.h>
#include "../../constants.h"
#include "../state.h"

class Motors {
public:
    Motors(byte frontLeftPin, 
        byte frontRightPin, 
        byte backLeftPin, 
        byte backRightPin);

    void setup();
    void run(State state);
private:
    byte pins[MOTOR_COUNT];
};

#endif