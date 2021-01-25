#ifndef STATE_H
#define STATE_H

#include "signal.h"

// Global state object - used for passing state of sensors and user signal to other hardware objects
class State {
public:
    State() {
        // Default starting state
        inDarkness = false;
        userSignal = nullptr;

        speed = 0;
        turningAngle = 0;

        temperature = 0;
        humidity = 0;

        isLightAutomatic = true;
        isHeadlightsOn = false;
        isHazardsOn = false;
        indicators = off;

        isHornOn = false;
    }

    // Sensor results
    float speed;
    float turningAngle;

    // Environment
    bool inDarkness;
    float temperature;
    float humidity;

    // Light states
    bool isLightAutomatic;
    bool isHeadlightsOn;
    bool isHazardsOn;
    direction indicators;

    // Horn
    bool isHornOn;

    // Signal from user controller
    Signal* userSignal;
};

#endif