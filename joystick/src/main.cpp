#include <Arduino.h>

int myFunction(int, int);

void setup() {
  int result = myFunction(2, 3);
  Serial.begin(9600);
  Serial.print("The result is: ");
  Serial.println(result);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(100);
}

int myFunction(int x, int y) {
  return x + y;
}
