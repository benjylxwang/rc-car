
#include <Arduino.h>
#include <stdint.h>
#include "sensors.h"

#include "../../constants.h"


Sensors::Sensors(byte photoResistorPin_) {
    photoResistorPin = photoResistorPin_;
}

void Sensors::setup() {
    pinMode(photoResistorPin, INPUT);
}

void Sensors::update(State& state) {
    // Photoresistor
    uint16_t lightLevels = analogRead(photoResistorPin);
    if (lightLevels > AMBIENT_LIGHT_THRESHOLD) state.inDarkness = false;
    else state.inDarkness = true;
}