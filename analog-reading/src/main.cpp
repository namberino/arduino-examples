#include "HardwareSerial.h"
#include <Arduino.h>

int sensorValue;
float ledval;

void setup()
{
	Serial.begin(9600);
	pinMode(A2, INPUT);
	pinMode(11, OUTPUT);
}

void loop()
{
	sensorValue = analogRead(A2);
	ledval = (float) sensorValue / 4;
	analogWrite(11, ledval);
	Serial.println((5. / 255.) * ledval); // or (5. / 1023.) * sensorValue
	delay(10);
}
