#ifndef SENSORS_H
#define SENSORS_H

#include "../state.h"
#include <DHT.h>

class Sensors
{
public:
    Sensors(byte photoResistorPin, byte dhtPin, byte thermisterPin);

    void setup();
    void update(State& state);
private:
    byte photoResistorPin;
    unsigned long darknessBeginning;

    DHT dht;
    byte dhtPin; // temperature and humidity
    unsigned long lastTempCheck;

    byte thermisterPin;
};

#endif