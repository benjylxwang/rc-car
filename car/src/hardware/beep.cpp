#include <Arduino.h>
#include "beep.h"

#include "../../constants.h"

Beep::Beep(byte buzzerPin)
{
    buzzer = buzzerPin;
}

void Beep::setup()
{
    pinMode(buzzer, OUTPUT);
}

void Beep::update(State& state)
{
    if (state.userSignal && state.userSignal->beep)
    {
        // Output tone
        tone(buzzer, BUZZER_FREQUENCY);
        state.isHornOn = true;
    }
    else if (!state.userSignal && state.isHornOn)
    {
        tone(buzzer, BUZZER_FREQUENCY);
    }
    else
    {
        noTone(buzzer);
        state.isHornOn = false;
    }
}