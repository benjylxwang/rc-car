#ifndef BEEP_H
#define BEEP_H

#include <stdint.h>
#include "../state.h"


class Beep {
public:
    Beep(byte buzzerPin);

    void setup();
    void update(State state);

private:
    byte buzzer;
};

#endif