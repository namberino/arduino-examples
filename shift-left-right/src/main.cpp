#include "HardwareSerial.h"
#include "Print.h"
#include <Arduino.h>

void updateRegister();

int dataPin = 9;
int clockPin = 11;
int latchPin = 12;

byte data = 0x7f;

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

	delay(500);

	//data /= 2; // shift right
	//data *= 2; // shift left
	//data = data / 2 + data * 128; // circular shift left
	data = data * 2 + data / 128; // circular shift right
}

void updateRegister()
{
	digitalWrite(latchPin, LOW);
	shiftOut(dataPin, clockPin, LSBFIRST, data);
	digitalWrite(latchPin, HIGH);
}
