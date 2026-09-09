#pragma once

#include <Arduino.h>
//#include "hal/ledc_types.h"

//-----------Pin Definition-------------

constexpr uint8_t BUTTON_PIN    = 4;
constexpr uint8_t BUZZER_PIN    = 5;
constexpr uint8_t LED_PIN       = 6;


//-----------Contants-------------------

constexpr uint32_t BUZZER_FREQ  = 500;
constexpr uint32_t SWITCH       = 1;
constexpr uint32_t TIMER_DELAY  = 500;
constexpr uint8_t BUTTON_MODE       = INPUT_PULLUP;
constexpr uint8_t BUTTON_PRESSED    = LOW;
constexpr uint8_t BUTTON_UNPRESSED  = HIGH;
constexpr uint8_t LED_ON            = HIGH;
constexpr uint8_t LED_OFF           = LOW;

//-----------Functions------------------

void devices_setup();

void ARDUINO_ISR_ATTR buttonISR();

//-----------Interrupts-----------------

extern volatile uint8_t state_button;


