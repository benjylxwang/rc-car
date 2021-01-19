#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "state.h"

class Controller
{
public:
    Controller(){};

    void setup();
    void update(State& state);
};

#endif