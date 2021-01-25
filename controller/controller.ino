#include <Arduino.h>

#include "src/sender.h"
#include "src/input.h"
#include "constants.h"

#include "src/inputs/JoystickAxis.h"
#include "src/inputs/ButtonInput.h"
#include "src/inputs/ToggleButton.h"

// RF Sender
Sender sender(RF_CE_PIN, RF_CSN_PIN);

// Movement Inputs
JoystickAxis throttle(THROTTLE_PIN);
JoystickAxis turning(TURNING_PIN);

// Lights
ToggleButton automaticLights(TOGGLE_AUTO_LIGHTS, INPUT_PULLUP, true);
ToggleButton manualHeadlights(TOGGLE_HEADLIGHTS, INPUT_PULLUP, true, true);
ToggleButton hazardLights(TOGGLE_HAZARD_LIGHTS, INPUT_PULLUP, true, true);

// Other
ButtonInput beep(BEEP_PIN, INPUT_PULLUP, true);

void setup() {
    sender.setup();

    // Inputs
    throttle.setup();
    turning.setup();

    automaticLights.setup();
    manualHeadlights.setup();
    hazardLights.setup();

    beep.setup();

    Serial.begin(115200);
}

void loop() {
    Input input;
    // Gather input data
    input.throttle = throttle.get();
    input.turning = turning.get();

    // Lights
    input.toggleAutoHeadlights = automaticLights.get();
    input.toggleHeadlights = manualHeadlights.get();
    input.toggleHazardlights = hazardLights.get();


    input.beepHorn = beep.get();


    Serial.print("Throttle: ");
    Serial.println(input.throttle);
    Serial.print("Turning: ");
    Serial.println(input.turning);
    Serial.print("Beep: ");
    Serial.println(input.beepHorn);

    // Send final input
    sender.send(input);

    // Pause so we only send input every so often
    delay(5);
}
