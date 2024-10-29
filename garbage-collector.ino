#include <Arduino.h>
#include <Servo.h>


Servo jointAxis;

void setup() {
  jointAxis.attach(0);
}

void loop() {
  jointAxis.write(0);
  delay(3000);
  jointAxis.write(180);
  delay(3000);

}
