#include "ButtonInput.h"

void ButtonInput::setup()
{
    pinMode(pin, inputType);
}

bool ButtonInput::get() {
    if (invert) return !digitalRead(pin);

    return digitalRead(pin);
}