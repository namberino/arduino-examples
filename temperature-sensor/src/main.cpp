#include <Arduino.h>
#include <DHT.h>

#define TYPE DHT11

int sensePin = 2;
DHT HT(sensePin, TYPE);
float humidity;
float temp;

void setup()
{
    Serial.begin(9600);
    HT.begin();
}

void loop()
{
    humidity = HT.readHumidity();
    temp = HT.readTemperature(false);

    String out = "Humidity: " + String(humidity, 2) + " | Temperature: " + String(temp, 2) + " Celcius";
    Serial.println(out);

    delay(500);
}
