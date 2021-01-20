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

    for (int i = 3; i >= 0; i--)
    {
        choosePin(i);
        byte digit;

        if (speed > 0 || i == 3)
        {
            digit = speed % 10;
            speed = speed / 10;
        }
        else
        {
            digit = 'x';
        }

        writeData(digitToHex(digit));

        // LED needs to light up
        if (digit != 'x') {
            delay(5);
            // Clear
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

    digitalWrite(pos, HIGH);
}

void Speedometer::writeData(int value)
{
    digitalWrite(latch, LOW);

    // Serial data
    shiftOut(data, clock, LSBFIRST, value);

    digitalWrite(latch, HIGH);
}

int Speedometer::digitToHex(byte digit)
{
    switch (digit)
    {
    case 0:
        return 0xc0;
    case 1:
        return 0xf9;
    case 2:
        return 0xa4;
    case 3:
        return 0xb0;
    case 4:
        return 0x99;
    case 5:
        return 0x92;
    case 6:
        return 0x82;
    case 7:
        return 0xf8;
    case 8:
        return 0x80;
    case 9:
        return 0x90;
    default:
        return 0xff;
    }
}