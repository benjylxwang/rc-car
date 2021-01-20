#include <Arduino.h>

#include "fakeController.h"
#include "../signal.h"

#include "../../constants.h"

FakeController::FakeController(){};

void FakeController::setup() {
    #if !VERBOSE
    // Begin serial if haven't already
    Serial.begin(SERIAL_BAUD_RATE);
    #endif
}

void FakeController::update(State& state) {
    byte instruction = Serial.read();

    if (state.userSignal == NULL) state.userSignal = (Signal*) calloc(1, sizeof(Signal));

    switch (instruction)
    {
    case 'l': // Indicate left
        state.userSignal->indicator = left;
        break;
    case 'r': // Indicate right
        state.userSignal->indicator = right;
        break;
    case 'i': // Turn off indicator
        state.userSignal->indicator = off;
        break;
    case 'h': // Toggle hazard lights
        state.userSignal->hazard = !state.userSignal->hazard;
        break;
    case 's': // Put a fake speed value in
        state.speed = 100;
        break;
    case 'S': // 'Stop' vehicle
        state.speed = 0;
        break;
    case 'f': // Push joystick forwards
        state.userSignal->forwardsMotion = 512;
        break;
    case 'b': // Pull joystick backwards (brake/reverse)
        state.userSignal->forwardsMotion = -512;
        break;
    case 'n': // joystick to neutral
        state.userSignal->forwardsMotion = 0;
        break;
    case 'B': // toggle BEEP
        state.userSignal->beep = !state.userSignal->beep;
        break;
    default:
        break;
    }
}