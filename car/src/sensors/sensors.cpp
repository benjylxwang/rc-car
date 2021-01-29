
#include <Arduino.h>
#include <stdint.h>
#include "sensors.h"

#include "../../constants.h"

Sensors::Sensors(byte photoResistorPin_, byte dhtPin_, byte thermisterPin_) : dht(dhtPin_, DHT11)
{
    photoResistorPin = photoResistorPin_;
    dhtPin = dhtPin_;
    thermisterPin = thermisterPin_;
}

void Sensors::setup()
{
    pinMode(photoResistorPin, INPUT);
    pinMode(thermisterPin, INPUT);
    lastTempCheck = 0;
}

void Sensors::update(State &state)
{
    // Photoresistor
    uint16_t lightLevels = analogRead(photoResistorPin);
    if (lightLevels > AMBIENT_LIGHT_THRESHOLD)
    {
        if (millis() - darknessBeginning > IN_DARKNESS_MINIMUM_TIME)
            state.inDarkness = false;
    }
    else
    {
        state.inDarkness = true;
        darknessBeginning = millis();
    }

    // Temperature and humidity
    if (millis() - lastTempCheck > TEMPERATURE_SENSOR_POLLING_RATE)
    {
        float h = dht.readHumidity();
        float t = dht.readTemperature();
        
        if (!isnan(h)) state.humidity = h;
        if (!isnan(t)) state.temperature = t;

        lastTempCheck = millis();
    }

    // Temperature - thermister - Not currently in use
    int thermisterValue = analogRead(thermisterPin);
    float v = thermisterValue * 5.0 / 1024;
    float Rt = 10 * v / (5 - v);
    float tempK = 1 / (log(Rt / 10) / 3950 + 1 / (273.15 + 15));
    float tempC = tempK - 273.15;
    // state.temperature = tempC;
}