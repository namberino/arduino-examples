#include "HardwareSerial.h"
#include "pins_arduino.h"
#include <Arduino.h>

int led = 8;
int lightSensor = A0;
int sensorValue;
boolean isLedOn = false;

void setup()
{
	Serial.begin(9600);
	pinMode(led, OUTPUT);
	pinMode(lightSensor, INPUT);
}

void loop()
{
	sensorValue = analogRead(lightSensor);
	float value = (5. / 1023.) * sensorValue;
	Serial.println(value);

	if (value < 0.10)
	{
		if (isLedOn)
		{
			digitalWrite(led, LOW);
		}
		else
		{
			digitalWrite(led, HIGH);
		}
		isLedOn = !isLedOn;
		delay(1000);
	}
}

