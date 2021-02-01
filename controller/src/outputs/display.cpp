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
        lastPrint = millis();

        // Temperature first
        lcd.setCursor(0, 0);
        if (state.temperature < 10 && state.temperature >= 0)
            lcd.print(" ");
        lcd.print(state.temperature, 1);
        lcd.print((char)0xDF);
        lcd.print("C");

        // Gap
        lcd.print("      ");

        // Then light information
        printLightInfo(state);

        // Then next line
        lcd.setCursor(0, 1);

        // Left indicator
        if ((state.indicators < 0 || state.isHazardsOn) && !leftIndicator)
        {
            leftIndicator = true;
            isInFlash = true;
            lastFlash = millis();
        }
        else if (state.indicators < 0 || state.isHazardsOn)
        {
            leftIndicator = true;
        }
        else
        {
            leftIndicator = false;
        }
        if (isInFlash && leftIndicator)
            lcd.print((char)0x7F);
        else
            lcd.print(" ");

        // Gap
        lcd.print("  ");

        // Speed
        lcd.setCursor(3, 1);
        if (state.speed < 10 && state.speed >= 0)
            lcd.print(" ");
        lcd.print(state.speed, 1);

        lcd.print(" km/hr  ");
        // Right indicator
        lcd.setCursor(15, 1);
        if ((state.indicators > 0 || state.isHazardsOn) && !rightIndicator)
        {
            rightIndicator = true;
            isInFlash = true;
            lastFlash = millis();
        }
        else if (state.indicators > 0 || state.isHazardsOn)
        {
            rightIndicator = true;
        }
        else
        {
            rightIndicator = false;
        }
        if (isInFlash && rightIndicator)
            lcd.print((char)0x7E);
        else
            lcd.print(" ");
    }

    if (millis() - lastFlash > DISPLAY_INDICATOR_FLASH_RATE)
    {
        isInFlash = !isInFlash;
        lastFlash = millis();
    }
}

void Display::printLightInfo(State state)
{
    lcd.setCursor(12, 0);
    if (state.isLightAutomatic)
        lcd.print("A");
    else
        lcd.print(" ");

    lcd.print(" ");

    lcd.setCursor(14, 0);
    if (state.isHeadlightsOn)
    {
        lcd.print((char)0x0D);
        lcd.print("D");
    }
    else
    {
        lcd.print("  ");
    }
}