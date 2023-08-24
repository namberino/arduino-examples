#include <Arduino.h>

int ledPin = LED_BUILTIN; 
int trigPin = 10; 
int echoPin = 9; 
int duration, distance; 

void setup()
{
    pinMode (ledPin, OUTPUT); 
    pinMode (trigPin, OUTPUT);
    pinMode (echoPin, INPUT); 
}
void loop()
{
    digitalWrite (ledPin, LOW); 
    digitalWrite (trigPin, HIGH);
    delay(50);

    digitalWrite (trigPin, LOW);
    duration = pulseIn(echoPin,HIGH);
    distance = (duration / 2) / 29.1;

    if(distance <= 20) 
        digitalWrite (ledPin, HIGH);
    delay(50);

    if(distance >= 20)// if no obstacle is there within 30 cm, the Led should turn off.
        digitalWrite (ledPin, LOW);
    delay(50);
    
    Serial.print("cm");
    Serial.println(distance);
}
