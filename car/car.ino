#include <Arduino.h>

#include "constants.h"

#include "src/state.h"

// Global state
State gState;

// Controls
#if USE_FAKE_CONTROLLER
#include "src/testing/fakeController.h"
FakeController controller;
#else
#include "src/receiver/controller.h"
Controller controller(RF_CE_PIN, RF_CSN_PIN);
#endif

void setup()
{
    controller.setup();
}

void loop()
{
    // Read sensors first to get correct state object

    // Get controls
    controller.update(gState);

    // Then reflect changes in state in hardware
}
