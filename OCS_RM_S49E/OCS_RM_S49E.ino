/*
 Name:		OCS_RM_S49E.ino
 Created:	12.06.2022 14:27:06
 Author:	Marc
*/


#define LED_STATUS 4
#define HAL_IN A1 // This must be A1 on Attiny85. Note there is diffrence between analog and digital pin number usage
#define OUT_PIN 0

#define THRESHOLD 20

uint32_t initialValue = 0;
uint32_t value = 0;

void setup() {
	// put your setup code here, to run once:

	pinMode(HAL_IN, INPUT);
	pinMode(LED_STATUS, OUTPUT);
	pinMode(OUTPUT, OUTPUT);
	digitalWrite(LED_STATUS, HIGH);

	// Get initial value
	initialValue = analogRead(HAL_IN);
}

void loop() {
	// put your main code here, to run repeatedly:

	value = analogRead(HAL_IN);

	if (initialValue + THRESHOLD < value)
	{
		digitalWrite(LED_STATUS, LOW);
		digitalWrite(OUT_PIN, LOW);
	}
	else
	{
		digitalWrite(LED_STATUS, HIGH);
		digitalWrite(OUT_PIN, HIGH);
	}

	delay(10);
}
