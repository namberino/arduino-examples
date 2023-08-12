#include "HardwareSerial.h"
#include "WString.h"
#include "pins_arduino.h"
#include <Arduino.h>
#include <Servo.h>

#define SENSOR A0

Servo myservo;

int readVal;

void setup()
{
	Serial.begin(9600);
	pinMode(SENSOR, INPUT);
	myservo.attach(9);
}

void loop()
{
	readVal = analogRead(SENSOR);
	Serial.print(readVal);
	Serial.print(" ");
	
	readVal = (float) readVal / 1023 * 180; // (readVal - 60) / (180 - 60) * 100

	Serial.println(readVal);
	myservo.write(readVal);
	delay(15);
}
