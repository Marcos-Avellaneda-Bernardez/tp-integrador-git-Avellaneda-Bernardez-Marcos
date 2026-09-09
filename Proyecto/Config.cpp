#include "Config.h"

volatile uint8_t state_button = 0;

void devices_setup() {
  // Left Side Setup
  pinMode(BUTTON_PIN_LEFT, BUTTON_MODE);
  pinMode(LED_PIN_LEFT, OUTPUT);
  ledcAttach(BUZZER_PIN_LEFT, BUZZER_FREQ_LEFT, 8);
  ledcWriteTone(BUZZER_PIN_LEFT, 0);
  attachInterrupt(BUTTON_PIN_LEFT, Left_buttonISR, FALLING);
  // For mor portability use
  /*
  attachInterrupt(digitalPinToInterrupt(BUTTOM_PIN_LEFT), 
    Left_buttonISR, 
    FALLING);
  */


  // Right Side Setup
  pinMode(BUTTON_PIN_RIGHT, BUTTON_MODE);
  pinMode(LED_PIN_RIGHT, OUTPUT);
  ledcAttach(BUZZER_PIN_RIGHT, BUZZER_FREQ_RIGHT, 8);
  ledcWriteTone(BUZZER_PIN_RIGHT, 0);
  attachInterrupt(BUTTON_PIN_RIGHT, Right_buttonISR, FALLING);
  // For mor portability use
  /*
  attachInterrupt(digitalPinToInterrupt(BUTTOM_PIN_RIGHT), 
    Right_buttonISR, 
    FALLING);
  */
}

void ARDUINO_ISR_ATTR Left_buttonISR() {
  state_button |= SWITCH_LEFT;
}

void ARDUINO_ISR_ATTR Right_buttonISR() {
  state_button |= SWITCH_RIGHT;
}
