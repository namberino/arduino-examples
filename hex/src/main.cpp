#include "HardwareSerial.h"
#include "Print.h"
#include <Arduino.h>

byte b = 0x1F;

void setup()
{
	Serial.begin(9600);
}

void loop()
{
	Serial.println(b, BIN); // DEC, DEC
	b++;
	delay(100);
}
