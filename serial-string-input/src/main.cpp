#include "HardwareSerial.h"
#include "WString.h"
#include <Arduino.h>

int leds[] = {8, 9, 10}; 
String onLed;
boolean states[] = {false, false, false};

void setup()
{
	Serial.begin(9600);
	for (int i = 0; i < 3; i++) 
	{
		pinMode(leds[i], OUTPUT);
	}
}

void loop()
{
	Serial.print("Which led: ");
	while (Serial.available() == 0) {}
	onLed = Serial.readString();
	
	if (onLed == "red")
	{
		digitalWrite(leds[0], states[0] ? LOW : HIGH);
		states[0] = !states[0];
		delay(500);
	}

	if (onLed == "green")
	{
		digitalWrite(leds[1], states[1] ? LOW : HIGH);
		states[1] = !states[1];
		delay(500);
	}

	if (onLed == "yellow")
	{
		digitalWrite(leds[2], states[2] ? LOW : HIGH);
		states[2] = !states[2];
		delay(500);
	}

	Serial.print("\n");
}

