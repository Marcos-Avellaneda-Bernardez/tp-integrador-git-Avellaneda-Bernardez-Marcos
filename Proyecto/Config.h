#pragma once

#include <Arduino.h>
#include <ESP32Servo.h>
//#include "hal/ledc_types.h"

//-----------Pin Definition-------------

constexpr uint8_t BUTTON_PIN_LEFT    = 4;
constexpr uint8_t BUZZER_PIN_LEFT    = 5;
constexpr uint8_t LED_PIN_LEFT       = 6;

constexpr uint8_t BUTTON_PIN_RIGHT   = 1;
constexpr uint8_t BUZZER_PIN_RIGHT   = 3;
constexpr uint8_t LED_PIN_RIGHT      = 2;

constexpr uint8_t SERVO_PIN          = 9;


//-----------Contants-------------------

constexpr uint32_t BUZZER_FREQ_LEFT  = 500;
constexpr uint32_t BUZZER_FREQ_RIGHT = 1000;

constexpr uint8_t SWITCH_LEFT        = 0x10;
constexpr uint8_t SWITCH_RIGHT       = 0x01;


constexpr int SERVO_MAX_ANGLE        = 180;
constexpr int SERVO_MIN_ANGLE        = 0;
constexpr int SERVO_STEP_ANGLE       = 10;

constexpr uint32_t TIMER_DELAY       = 500;
constexpr uint32_t DEBOUNCE_DELAY    = 50000;
constexpr uint8_t BUTTON_MODE        = INPUT_PULLUP;
constexpr uint8_t BUTTON_PRESSED     = LOW;
constexpr uint8_t BUTTON_UNPRESSED   = HIGH;
constexpr uint8_t LED_ON             = HIGH;
constexpr uint8_t LED_OFF            = LOW;

//-----------Functions------------------

void devices_setup();

void ARDUINO_ISR_ATTR Left_buttonISR();
void ARDUINO_ISR_ATTR Right_buttonISR();

//-----------Interrupts Variables-------

extern volatile uint8_t state_button;
extern Servo my_servo;
extern int servo_angle;


