#include <Arduino.h>

#define GREEN_LED 8
#define RED_LED 9
#define BUZZER 10
#define LIGHT_SENSOR A0

int readVal;
boolean redRun = false;
boolean greenRun = true;

void setup()
{
    // Serial.begin(9600);
    pinMode(GREEN_LED, OUTPUT);
    pinMode(RED_LED, OUTPUT);
    pinMode(BUZZER, OUTPUT);
    pinMode(LIGHT_SENSOR, INPUT);
}

void loop()
{
    readVal = analogRead(LIGHT_SENSOR);

    if (readVal > 1010)
    {
        if (!redRun)
        {
            digitalWrite(BUZZER, HIGH);
            delay(1);
            digitalWrite(BUZZER, LOW);
            redRun = true;
            greenRun = false;
        }
        digitalWrite(GREEN_LED, LOW);
        digitalWrite(RED_LED, HIGH);
    }
    else
    {
        if (!greenRun)
        {
            digitalWrite(BUZZER, HIGH);
            delay(2);
            digitalWrite(BUZZER, LOW);
            redRun = false;
            greenRun = true;
        }
        digitalWrite(GREEN_LED, HIGH);
        digitalWrite(RED_LED, LOW);
    }
    

    // Serial.println(readVal);
}
