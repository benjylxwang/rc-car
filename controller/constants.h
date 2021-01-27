#ifndef CONSTANTS_H
#define CONSTANTS_H

#define VERBOSE 0

// ===== PINS =====
// RF Sender
#define RF_CE_PIN 9
#define RF_CSN_PIN 10

// = movement pins
#define THROTTLE_PIN A4
#define TURNING_PIN A5

// = Light controls
#define TOGGLE_HEADLIGHTS 7
#define TOGGLE_AUTO_LIGHTS 6
#define TOGGLE_HAZARD_LIGHTS 5
#define INDICATOR_LEFT 3
#define INDICATOR_RIGHT 4


// = Other controls
#define BEEP_PIN 8

// MOSI pins for sender (These are fixed for different arduino types)
#define RF_SCK_PIN 13
#define RF_MISO PIN 12
#define RF_MOSI_PIN 11

// ==== RF Sender Settings
#define RF_CONTROLLER_ID 0
#define RF_CAR_ID 1

#endif
