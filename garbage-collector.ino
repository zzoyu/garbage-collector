#include <Arduino.h>
#include <Servo.h>
#include <HCSR04.h>

Servo jointAxis;
HCSR04 distanceSensor(2,3);

void setup() {
  jointAxis.attach(0);
  Serial.begin(9600);
}

void loop() {
  jointAxis.write(0);
  delay(3000);
  jointAxis.write(180);
  delay(3000);
  Serial.println(distanceSensor.dist());
}
