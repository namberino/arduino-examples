#include "HardwareSerial.h"
#include "Print.h"
#include <Arduino.h>

void updateRegister();

int dataPin = 9;
int clockPin = 11;
int latchPin = 12;

byte data = 0x56;

void setup()
{
	Serial.begin(9600);
	pinMode(dataPin, OUTPUT);
	pinMode(clockPin, OUTPUT);
	pinMode(latchPin, OUTPUT);
}

void loop()
{
	updateRegister();
	Serial.println(data, BIN);

	delay(1000);

	data = ~data; // or just subtract data from 255 because the flipped data and data added up would be 255
}

void updateRegister()
{
	digitalWrite(latchPin, LOW);
	shiftOut(dataPin, clockPin, LSBFIRST, data);
	digitalWrite(latchPin, HIGH);
}

