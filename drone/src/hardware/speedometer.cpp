#include "speedometer.h"

Speedometer::Speedometer(byte digit1, byte digit2, byte digit3, byte digit4, byte latchPin, byte clockPin, byte dataPin)
{
    digits[0] = digit1;
    digits[1] = digit2;
    digits[2] = digit3;
    digits[3] = digit4;

    latch = latchPin;
    clock = clockPin;
    data = dataPin;
}

void Speedometer::setup()
{
    pinMode(latch, OUTPUT);
    pinMode(clock, OUTPUT);
    pinMode(data, OUTPUT);

    for (int i = 0; i < 4; i++)
        pinMode(digits[i], OUTPUT);
}

void Speedometer::update(State state)
{
    int speed = (int)state.speed;

    // First put decimal in
    byte decimal = (int)(state.speed * 10) % 10;
    choosePin(3);
    writeData(digitToHex(decimal));
    delay(1);
    writeData(0xff);

    for (int i = 2; i >= 0; i--)
    {
        choosePin(i);
        byte digit;

        if (speed > 0 || i == 2)
        {
            digit = speed % 10;
            speed = speed / 10;
        }
        else
        {
            digit = 'x';
        }

        if (i == 2) writeData(digitToHex(digit, true));
        else writeData(digitToHex(digit));

        // LED needs to light up
        if (digit != 'x') {
            // Clear
            delay(1);
            writeData(0xff);
        }
    }
}

void Speedometer::choosePin(byte pos)
{
    for (int i = 0; i < 4; i++)
    {
        digitalWrite(digits[i], LOW);
    }

    digitalWrite(digits[pos], HIGH);
}

void Speedometer::writeData(int value)
{
    digitalWrite(latch, LOW);

    // Serial data
    shiftOut(data, clock, LSBFIRST, value);

    digitalWrite(latch, HIGH);
}

int Speedometer::digitToHex(byte digit, bool dp = false)
{
    int result;
    switch (digit)
    {
    case 0:
        result = 0xc0;
        break;
    case 1:
        result = 0xf9;
        break;
    case 2:
        result = 0xa4;
        break;
    case 3:
        result = 0xb0;
        break;
    case 4:
        result = 0x99;
        break;
    case 5:
        result = 0x92;
        break;
    case 6:
        result = 0x82;
        break;
    case 7:
        result = 0xf8;
        break;
    case 8:
        result = 0x80;
        break;
    case 9:
        result = 0x90;
        break;
    default:
        result = 0xff;
        break;
    }

    if (dp) return result & 0x7f;
    else return result;
}