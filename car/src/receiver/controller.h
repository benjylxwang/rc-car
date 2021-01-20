#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../state.h"
#include "../../constants.h"
#include <RF24.h>

class Controller
{
public:
    Controller(byte cePin, byte csPin);

    void setup();
    void update(State& state);

private:
    RF24 receiver;
};

#endif