#include <Arduino.h>

#include "src/sender.h"
#include "src/input.h"
#include "constants.h"
#include "src/state.h"

#include "src/inputs/JoystickAxis.h"
#include "src/inputs/ButtonInput.h"
#include "src/inputs/ToggleButton.h"
#include "src/inputs/IndicatorControl.h"

#include "src/outputs/display.h"

// RF Sender
Sender sender(RF_CE_PIN, RF_CSN_PIN);
State carState;

// Movement Inputs
JoystickAxis throttle(THROTTLE_PIN);
JoystickAxis turning(TURNING_PIN);

// Lights
ToggleButton automaticLights(TOGGLE_AUTO_LIGHTS, INPUT_PULLUP, true);
ToggleButton manualHeadlights(TOGGLE_HEADLIGHTS, INPUT_PULLUP, true, true);
ToggleButton hazardLights(TOGGLE_HAZARD_LIGHTS, INPUT_PULLUP, true, true);
IndicatorControl indicators(INDICATOR_LEFT, INDICATOR_RIGHT, INPUT_PULLUP);

// Other
ButtonInput beep(BEEP_PIN, INPUT_PULLUP, true);

// Outputs
Display display;

void setup()
{
#if VERBOSE
    Serial.begin(115200);
#endif

    sender.setup();

    // Inputs
    throttle.setup();
    turning.setup();

    automaticLights.setup();
    manualHeadlights.setup();
    hazardLights.setup();
    indicators.setup();

    beep.setup();

    display.setup();
}

void loop()
{
    Input input;
    // Gather input data
    input.throttle = throttle.get();
    input.turning = turning.get();

    // Lights
    input.toggleAutoHeadlights = automaticLights.get();
    input.toggleHeadlights = manualHeadlights.get();
    input.toggleHazardlights = hazardLights.get();
    input.indication = indicators.get();

    input.beepHorn = beep.get();

    // Send final input
    sender.send(input, carState);

#if VERBOSE
    Serial.print("Motion: (");
    Serial.print(carState.speed);
    Serial.print(", ");
    Serial.print(carState.turningAngle);
    Serial.print(") Indicator: ");
    Serial.print(carState.indicators);
    Serial.print(" Auto Lights: ");
    Serial.print(carState.isLightAutomatic);
    Serial.print(" Headlights: ");
    Serial.print(carState.isHeadlightsOn);
    Serial.print(" Hazard: ");
    Serial.print(carState.isHazardsOn);
    Serial.print(" Beep: ");
    Serial.print(carState.isHornOn);
    Serial.print(" T: ");
    Serial.print(carState.temperature);
    Serial.print(" H: ");
    Serial.print(carState.humidity);
    Serial.println();
#endif

    // Pause so we only send input every so often
    display.printState(carState);
    delay(5);
}
