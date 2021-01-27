#ifndef PINS_H
#define PINS_H

// ------------- PINS ----------------
// == Lights
#define LIGHTS_HEADLIGHTS_PIN 4
#define LIGHTS_BRAKELIGHTS_PIN 2
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

// == Servo Motor - Steering
#define STEERING_PIN 5

// == Speedometer
#define SPEEDOMETER_DIGIT_1 25
#define SPEEDOMETER_DIGIT_2 24
#define SPEEDOMETER_DIGIT_3 23
#define SPEEDOMETER_DIGIT_4 22

#define SPEEDOMETER_DATA 26
#define SPEEDOMETER_LATCH 27
#define SPEEDOMETER_CLOCK 28

// == RF Receiver
#define RF_CE_PIN 49
#define RF_CSN_PIN 53

// MOSI pins for receiver (These are fixed for different arduino types: we are using an Arduino Mega2560)
#define RF_SCK_PIN 52
#define RF_MISO PIN 50
#define RF_MOSI_PIN 51


#endif