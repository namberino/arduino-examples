#include <Arduino.h>

void updateRegister();

int latchPin = 11;
int clockPin = 9;
int dataPin = 12;

byte LEDs = 0x00;

void setup()
{
	pinMode(latchPin, OUTPUT);
	pinMode(clockPin, OUTPUT);
	pinMode(dataPin, OUTPUT);
}

void loop()
{
	LEDs = 0;
	updateRegister();
	delay(500);

	for (int i = 0; i < 255; i++) // i = i * 2 + 1 and LEDs = i for an interesting pattern
	{
		LEDs++;
		updateRegister();
		delay(500);
	}
}

void updateRegister()
{
	digitalWrite(latchPin, LOW);
	shiftOut(dataPin, clockPin, LSBFIRST, LEDs);
	digitalWrite(latchPin, HIGH);
}
