#include "garbage-collector.h"

Servo jointAxis;
HCSR04 distanceSensor(PIN_SENSOR_DIST_TRIG, PIN_SENSOR_DIST_ECHO);

int distance = 0;
volatile bool isShock = false;
unsigned long shockTime = 0;

void setup() {
  Serial.begin(9600);
  jointAxis.attach(PIN_SERVO);
  jointAxis.write(0);
  pinMode(PIN_SENSOR_SHOCK, INPUT);
  attachInterrupt(digitalPinToInterrupt(PIN_SENSOR_SHOCK), handleShock, RISING);

  displayInit();
}

void loop() {  
  distance = distanceSensor.dist();
  Serial.println(distance);
  
  if ( distance < 10 && distance > 0) {
    drawSmile();
    openLid();
  }
  else if ( isShock && (millis() - shockTime < 5000) ) {
    drawOuch();
    openLid();
  }
  else {
    isShock = false;
    drawNormal();
    closeLid();
  }

  delay(200UL);
}


void openLid() {
  jointAxis.write(0);
}

void closeLid() {
  jointAxis.write(180);
}

void handleShock() {
  if(isShock) return;
  shockTime = millis();
  isShock = true;
  Serial.println("Shock detected!");
}