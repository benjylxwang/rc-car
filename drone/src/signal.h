#ifndef SIGNAL_H
#define SIGNAL_H

#include <stdint.h>

typedef enum {
    off,
    left,
    right
} direction;

class Signal
{
public:
    // Steering controls + throttle
    int16_t forwardsMotion;
    int16_t rightMotion;

    // Lights
    bool toggleAutoLights;
    bool headlightsOn;
    direction indicator; 

    // Other
    bool hazard;
    bool beep;
};

#endif