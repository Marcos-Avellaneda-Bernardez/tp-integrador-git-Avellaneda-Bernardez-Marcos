#include "Config.h"

volatile uint8_t state_button = 0;

void devices_setup() {
  pinMode(BUTTON_PIN, BUTTON_MODE);

  ledcAttach(BUZZER_PIN, BUZZER_FREQ, 8);

  pinMode(LED_PIN, OUTPUT);

  ledcWriteTone(BUZZER_PIN, 0);

  attachInterrupt(BUTTON_PIN, buttonISR, FALLING);

  // For mor portability use
  /*
  attachInterrupt(digitalPinToInterrupt(BUTTOM_PIN), 
    buttonISR, 
    FALLING);
  */
}

void ARDUINO_ISR_ATTR buttonISR() {
  state_button |= SWITCH;
}
