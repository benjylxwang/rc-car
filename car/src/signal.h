#ifndef SIGNAL_H
#define SIGNAL_H

typedef enum {
    off,
    left,
    right
} direction;

class Signal
{
public:
    // Steering controls + throttle
    int forwardsMotion;
    int rightMotion;

    // Lights
    bool toggleAutoLights;
    bool headlightsOn;
    direction indicator; 

    // Other
    bool hazard;
    bool beep;
};

#endif