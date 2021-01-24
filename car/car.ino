#include <Arduino.h>

#include "constants.h"

#include "src/state.h"
#include "src/sensors/sensors.h"

#include "src/hardware/lights.h"
#include "src/hardware/beep.h"
#include "src/hardware/speedometer.h"
#include "src/hardware/motor.h"
#include "src/hardware/steering.h"

// Global state
State gState;

// Hardware
Lights lights(LIGHTS_HEADLIGHTS_PIN, LIGHTS_BRAKELIGHTS_PIN, LIGHTS_INDICATOR_LEFT_PIN, LIGHTS_INDICATOR_RIGHT_PIN);
Beep beep(BEEP_PIN);
Speedometer speedometer(SPEEDOMETER_DIGIT_1, SPEEDOMETER_DIGIT_2, SPEEDOMETER_DIGIT_3, SPEEDOMETER_DIGIT_4, SPEEDOMETER_LATCH, SPEEDOMETER_CLOCK, SPEEDOMETER_DATA);
Motor motor(MOTOR_ENABLE_PIN, MOTOR_IN_A, MOTOR_IN_B);
Steering steering(STEERING_PIN);

// Sensors
Sensors sensors(PHOTORESISTOR_PIN);

// Controls
#if USE_FAKE_CONTROLLER
#include "src/testing/fakeController.h"
FakeController controller;
#else 
#include "src/receiver/controller.h"
Controller controller(RF_CE_PIN, RF_CSN_PIN);
#endif



void setup() {
    #if VERBOSE
    Serial.begin(SERIAL_BAUD_RATE);
    #endif
    sensors.setup();

    // Hardware
    lights.setup();
    beep.setup();
    // speedometer.setup();
    motor.setup();
    steering.setup();

    controller.setup();
}

void loop() {
    // Read sensors first to get correct state object
    sensors.update(gState);

    // Get controls
    controller.update(gState);

    // Then reflect changes in state in hardware
    lights.update(gState);
    beep.update(gState);
    // speedometer.update(gState);
    motor.update(gState);
    steering.update(gState);
}
