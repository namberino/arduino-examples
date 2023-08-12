#include "HardwareSerial.h"
#include "pins_arduino.h"
#include <Arduino.h>

int xpin = A0;
int ypin = A1;
int switchpin = 6;
int xval;
int yval;
int sval;

void setup()
{
	Serial.begin(9600);

	pinMode(xpin, INPUT);
	pinMode(ypin, INPUT);
	pinMode(switchpin, INPUT);
	pinMode(8, OUTPUT);
	digitalWrite(switchpin, HIGH);
}

void loop()
{
	xval = analogRead(xpin);
	yval = analogRead(ypin);
	sval = digitalRead(switchpin);

	Serial.print("X value: ");
	Serial.print(xval);
	Serial.print(" Y value: ");
	Serial.print(yval);
	Serial.print(" Switch state: ");
	Serial.println(sval);

	xval = map(xval, 0, 1023, 1, 20);
	yval = map(yval, 0, 1023, 1, 20);

	digitalWrite(8, HIGH);
	delay(xval);
	digitalWrite(8, LOW);
	delay(yval);
}
