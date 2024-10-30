#ifndef __GARAGE_COLLECTOR_H__
#define __GARAGE_COLLECTOR_H__

#include <Arduino.h>
#include <Servo.h>
#include <HCSR04.h>

#define PIN_SENSOR_SHOCK 2  // 충격 감지 센서 데이터 핀 위치 (2번 DI, 인터럽트 가능 핀)
#define PIN_SENSOR_DIST_TRIG 3 // 초음파 센서 데이터 핀 위치 (4번 DO)
#define PIN_SENSOR_DIST_ECHO 4 // 초음파 센서 데이터 핀 위치 (3번 DI)
#define PIN_SERVO 5         // 서보모터 제어 핀 위치 (5번 PWM 핀)

void openLid();
void closeLid();


#endif // __GARAGE_COLLECTOR_H__