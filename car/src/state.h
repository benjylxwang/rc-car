#ifndef STATE_H
#define STATE_H

#include "signal.h"

// Global state object - used for passing state of sensors and user signal to other hardware objects
class State {
public:
    State() {
        // Zero everything
        inDarkness = false;
        userSignal = NULL;
    }

    // Sensor results
    bool inDarkness;
    float speed;

    // Signal from user controller
    Signal* userSignal;
};

#endif