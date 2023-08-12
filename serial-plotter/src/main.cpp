#include <Arduino.h>

float sinVal, cosVal, i, parab1, parab2;

void setup() 
{
    Serial.begin(9600);
}

void loop()
{
    // for (i = 0; i <= 2 * 3.14159265; i += 0.01)
    // {
    //     Serial.println(i);

    //     sinVal = sin(i) + 2;
    //     cosVal = cos(10 * i);
    //     Serial.print(">sin:");
    //     Serial.println(sinVal);
    //     Serial.print(">cos:");
    //     Serial.println(cosVal);
    // }

    for (i = -4; i <= 4; i += .01)
    {
        parab1 = i * i;
        sinVal = sin(i);
        parab2 = parab1 * sinVal;

        Serial.print(">parab1:");
        Serial.println(parab1);

        Serial.print(">parab2:");
        Serial.println(parab2);
    }
}
