#include <Arduino.h>

#include "display.h"
#include "../../constants.h"

Display::Display() : lcd(0x27, 16, 2)
{
}

void Display::setup()
{
    lcd.init();
    lcd.backlight();
}

void Display::printState(State state)
{
    if (millis() - lastPrint > DISPLAY_UPDATE_RATE)
    {
        lcd.clear();
        lastPrint = millis();
        lcd.setCursor(0, 0);
        // Temperature first
        lcd.print(state.temperature);
        lcd.print("C");

        // Then light information
        printLightInfo(state);

        // Then next line
        lcd.setCursor(0, 1);

        // Left indicator
        if (state.indicators < 0)
        {
            lcd.print("<");
        }

        // Speed
        lcd.setCursor(3, 1);
        lcd.print(state.speed);
        lcd.print(" km/hr");

        // Right indicator
        lcd.setCursor(15, 1);
        if (state.indicators > 0)
        {
            lcd.print(">");
        }
    }
}

void Display::printLightInfo(State state)
{
    lcd.setCursor(13, 0);
    if (state.isHeadlightsOn)
        lcd.print("H");

    lcd.setCursor(14, 0);
    if (state.isLightAutomatic)
        lcd.print("A");

    lcd.setCursor(15, 0);
    if (state.isHazardsOn)
        lcd.print("0x9650");
}