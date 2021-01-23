#ifndef PINS_H
#define PINS_H

// ------------- PINS ----------------
// == Lights
#define LIGHTS_HEADLIGHTS_PIN 4
#define LIGHTS_BRAKELIGHTS_PIN 5
#define LIGHTS_INDICATOR_LEFT_PIN 7 
#define LIGHTS_INDICATOR_RIGHT_PIN 8

// == Beep
#define BEEP_PIN 6

// == Sensors
#define PHOTORESISTOR_PIN A0

// == Motors - Throttle
#define MOTOR_ENABLE_PIN 3
#define MOTOR_IN_A A4
#define MOTOR_IN_B A5

// == Speedometer
#define SPEEDOMETER_DIGIT_1 13
#define SPEEDOMETER_DIGIT_2 12
#define SPEEDOMETER_DIGIT_3 11
#define SPEEDOMETER_DIGIT_4 10

#define SPEEDOMETER_DATA A1
#define SPEEDOMETER_LATCH A2
#define SPEEDOMETER_CLOCK A3

// == RF Receiver
#define RF_CE_PIN 9
#define RF_CSN_PIN 10

// MOSI pins for receiver (These are fixed for different arduino types)
#define RF_SCK_PIN 13
#define RF_MISO PIN 12
#define RF_MOSI_PIN 11


#endif