#include <Arduino.h>

/*
  By default, the input will return random values until the button is pressed
  With INPUT_PULLUP, the input will return 1 / HIGH until the button is pressed
*/

void setup()
{
    // pinMode(7, INPUT_PULLUP);
    Serial.begin(9600);
}

void loop()
{
    Serial.print("Pin 7 value: ");
    Serial.println(digitalRead(7));
}
