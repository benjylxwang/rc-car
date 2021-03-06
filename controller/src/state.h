#ifndef STATE_H
#define STATE_H

// Global state object - used for passing state of sensors and user signal to other hardware objects
class State {
public:
    State() {
        // Default starting state
        inDarkness = false;

        speed = 0;
        turningAngle = 0;

        temperature = 0;
        humidity = 0;

        isLightAutomatic = true;
        isHeadlightsOn = false;
        isHazardsOn = false;
        indicators = 0;

        isHornOn = false;
    }

    // Sensor results
    float speed;
    int8_t turningAngle;

    // Environment
    bool inDarkness;
    float temperature;
    float humidity;

    // Light states
    bool isLightAutomatic;
    bool isHeadlightsOn;
    bool isHazardsOn;
    int8_t indicators;

    // Horn
    bool isHornOn;
};

#endif