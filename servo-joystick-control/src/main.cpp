#include <Arduino.h>
#include <Servo.h>

Servo servo;

int xpin = A0;
int xval;
int servopin = 8;
int buzzpin = 3;

void setup()
{
    Serial.begin(9600);
    servo.attach(servopin);
    servo.write(90);
    pinMode(xpin, INPUT);
    pinMode(buzzpin, OUTPUT);
}

void loop()
{
    xval = analogRead(xpin);

    Serial.print("Joystick X: ");
    Serial.print(xval);

    // if (xval > 525)
    // {
    //     analogWrite(buzzpin, xval / 4);
    // }
    // if (xval < 515)
    // {
    //     analogWrite(buzzpin, (1023 - xval) / 4);
    // }

    xval = (float)xval / 1023 * 180;

    Serial.print(" Servo pos: ");
    Serial.println(xval);
    servo.write(180 - xval);
    delay(15);
}
