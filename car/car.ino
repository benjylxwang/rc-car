#include <Arduino.h>

#include "constants.h"

#include "src/state.h"
#include "src/sensors/sensors.h"
#include "src/hardware/lights.h"

// Global state
State gState;

// Hardware
Lights lights(LIGHTS_HEADLIGHTS_PIN, LIGHTS_BRAKELIGHTS_PIN, LIGHTS_INDICATOR_LEFT_PIN, LIGHTS_INDICATOR_RIGHT_PIN);

// Sensors
Sensors sensors(PHOTORESISTOR_PIN);

// Controls
#if USE_FAKE_CONTROLLER
#include "src/testing/fakeController.h"
FakeController controller;
#else 
#include "src/controller.h"
Controller controller;
#endif



void setup() {
    #if VERBOSE
    Serial.begin(9600);
    #endif
    sensors.setup();
    lights.setup();
    controller.setup();
}

void loop() {
    // Read sensors first to get correct state object
    sensors.update(gState);

    // Update controls
    controller.update(gState);

    // Then reflect changes in state in hardware
    lights.update(gState);
}