#include "lights.h"
#include "../../constants.h"

Lights::Lights(byte headlightsPin_, byte brakelightsPin_, byte indicatorLeftPin_, byte indicatorRightPin_)
{
    headlights = headlightsPin_;
    brakelights = brakelightsPin_;
    indicatorLeft = indicatorLeftPin_;
    indicatorRight = indicatorRightPin_;

    // Default to automatic lights
    isAutomatic = true;
}

void Lights::setup()
{
    pinMode(headlights, OUTPUT);
    pinMode(brakelights, OUTPUT);
    pinMode(indicatorLeft, OUTPUT);
    pinMode(indicatorRight, OUTPUT);
}

void Lights::update(State state)
{
    // First check if we need to change automatic
    if (state.userSignal && state.userSignal->toggleAutoLights)
    {
        isAutomatic = !isAutomatic;
    }

    // Headlights
    if (isAutomatic)
    {
        if (state.inDarkness)
            lightsOn();
        else
            lightsOff();
    }
    else
    {
        if (state.userSignal && state.userSignal->headlightsOn)
            lightsOn();
        else
            lightsOff();
    }

    // Brake lights brighter/dimmer
    if (state.speed > 0 && state.userSignal && state.userSignal->forwardsMotion < 0)
    {
        // Speed is non zero and user is moving backwards, apply brake
        analogWrite(brakelights, LIGHTS_BRIGHT_LEVEL);
    }
    else
    {
        analogWrite(brakelights, isLightOn ? LIGHTS_DIM_LEVEL : LIGHTS_OFF);
    }

    // Hazard lights
    if (state.userSignal && state.userSignal->hazard)
    {
        // Flash both indicators
        flashIndicator(indicatorLeft);
        flashIndicator(indicatorRight);
    }
    else
    {
        // Turn indicators on/off
        if (state.userSignal && state.userSignal->indicator == left)
        {
            flashIndicator(indicatorLeft);
            digitalWrite(indicatorRight, LIGHTS_OFF);
        }
        else if (state.userSignal && state.userSignal->indicator == right)
        {
            flashIndicator(indicatorRight);
            digitalWrite(indicatorLeft, LIGHTS_OFF);
        }
        else
        {
            // Turn both indicators off
            digitalWrite(indicatorLeft, LIGHTS_OFF);
            digitalWrite(indicatorRight, LIGHTS_OFF);
        }
    }
}

void Lights::lightsOn()
{
    isLightOn = true;
    digitalWrite(headlights, HIGH);
}

void Lights::lightsOff()
{
    isLightOn = false;
    digitalWrite(headlights, LIGHTS_OFF);
}

void Lights::flashIndicator(byte pin)
{
    // Flip bit every LIGHT_INDICATOR_FLASH_PERIOD_MILLISECONDS
    if (millis() > startTime + LIGHT_INDICATOR_FLASH_PERIOD_MILLISECONDS)
    {
        indicatorLightState = !indicatorLightState;
        startTime = millis();
    }

    // Turn light on and off based on bit
    if (indicatorLightState)
        analogWrite(pin, LIGHTS_BRIGHT_LEVEL);
    else
        digitalWrite(pin, LIGHTS_OFF);
}