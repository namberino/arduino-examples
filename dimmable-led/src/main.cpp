#include "HardwareSerial.h"
#include "pins_arduino.h"
#include <Arduino.h>

#define BUTTON_PIN 4
#define SWITCH_PIN 5
#define LED 9

byte button;
byte switch_pin;
int threshold = 15;
boolean isLower;
int count;
int ledVal;

void setup()
{
	Serial.begin(9600);
	pinMode(BUTTON_PIN, INPUT_PULLUP);
	pinMode(SWITCH_PIN, INPUT_PULLUP);
	pinMode(LED, OUTPUT);

	count = 0;
}

void loop()
{
	button = digitalRead(BUTTON_PIN);
	switch_pin = digitalRead(SWITCH_PIN);

	if (switch_pin == 0)
	{
		isLower = false;
	}
	else 
	{
		isLower = true;
	}

	if (button == 0)
	{
		count -= isLower ? 1 : -1;

		if (count <= 0)
		{
			count = 0;
		}

		if (count >= threshold)
		{
			count = threshold;
		}

	}

	ledVal = (float) count / threshold * 255;
	analogWrite(LED, ledVal);

	Serial.print("Button: ");
	Serial.print(button);
	Serial.print(" Switch: ");
	Serial.print(switch_pin);
	Serial.print(" Count: ");
	Serial.print(count);
	Serial.print(" LED value: ");
	Serial.print(ledVal);
	Serial.println();

	delay(100);
}
