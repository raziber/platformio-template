#include <Arduino.h>

void setup() {
  Serial.begin(9600);
  delay(1000);

  pinMode(A0, INPUT);
}

void loop() {
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);
}
