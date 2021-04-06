#ifndef PINS_H
#define PINS_H

// ------------- PINS ----------------
// == Sensors ..... don't know what we'll need yet
#define ALTITUDE_PIN 12

// == Motors
#define MOTOR_FRONT_LEFT 1
#define MOTOR_FRONT_RIGHT 2
#define MOTOR_BACK_LEFT 3
#define MOTOR_BACK_RIGHT 4

// == RF Receiver
#define RF_CE_PIN 49
#define RF_CSN_PIN 53

// MOSI pins for receiver (These are fixed for different arduino types: we are using an Arduino Mega2560)
#define RF_SCK_PIN 52
#define RF_MISO PIN 50
#define RF_MOSI_PIN 51


#endif