#include "ToggleButton.h"

void ToggleButton::setup()
{
    pinMode(pin, inputType);
    currentValue = false;
}

bool ToggleButton::get()
{
    bool current;
    if (invert)
        current = !digitalRead(pin);
    else
        current = digitalRead(pin);

    // Only return true if last state was false and current state is true
    bool result = !lastState && current;
    lastState = current;

    if (persist)
    {
        if (result) {
            // Flip value if button was pressed
            currentValue = !currentValue;
        }
        return currentValue;
    }
    else
    {
        return result;
    }
}