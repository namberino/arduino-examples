#include <Arduino.h>

void binaryCounter(int num);

int led[] = {8, 9, 10, 11};

void setup()
{
	for (int i = 0; i < 4; i++) 
	{
		pinMode(led[i], OUTPUT);
	}
}

void loop()
{
	for (int i = 0; i <= 15; i++)
	{
		binaryCounter(i);
		delay(1500);
	}
}

void binaryCounter(int num)
{
	int binaryNum[4];

	for (int i = 3; i >= 0; i--)
	{
		binaryNum[i] = num % 2;
		num /= 2;
	}

	for (int i = 3; i >= 0; i--)
	{
		if (binaryNum[i] == 1)
		{
			digitalWrite(led[i], HIGH);
		}
		else 
		{
			digitalWrite(led[i], LOW);
		}
	}
}
