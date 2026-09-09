#include "Config.h"

unsigned long last_press_left_millis;
unsigned long last_press_right_millis;

void setup() {
  Serial.begin(115200);

  devices_setup();
  
  last_press_left_millis  = 0;
  last_press_right_millis = 0;

  Serial.println();
  Serial.println("Press buttons on GPIO 4 (←) or GPIO 1 (→)");
  Serial.println();
}

void loop() {
  //  If Left Side Was Press
  if ( state_button & SWITCH_LEFT){
    unsigned long current_time_left_millis = millis();

    if (current_time_left_millis - last_press_left_millis > TIMER_DELAY) {
      ledcWriteTone(BUZZER_PIN_LEFT, BUZZER_FREQ_LEFT);
      digitalWrite(LED_PIN_LEFT, LED_ON);
    }
    
    ledcWriteTone(BUZZER_PIN_LEFT, 0);
    digitalWrite(LED_PIN_LEFT, LED_OFF);
    state_button = 0x0;
    last_press_left_millis = current_time_left_millis;
  }


  //  If Right Side Was Press
  if ( state_button & SWITCH_RIGHT){
    unsigned long current_time_right_millis = millis();

    if (current_time_right_millis - last_press_right_millis > TIMER_DELAY) {
      ledcWriteTone(BUZZER_PIN_RIGHT, BUZZER_FREQ_RIGHT);
      digitalWrite(LED_PIN_RIGHT, LED_ON);
    }
    
    ledcWriteTone(BUZZER_PIN_RIGHT, 0);
    digitalWrite(LED_PIN_RIGHT, LED_OFF);
    state_button = 0x0;
    last_press_right_millis = current_time_right_millis;
  }

  delay(1000);
}

/*
void loop() {
  switch (state_button) {
    case LEFT_SWITCH:
      Serial.printf("LEFT: %d  RIGHT: %d\n", CounterLeft, CounterRight);
      ledcWriteTone(BUZZER_PIN_LEFT, 500);
      delay(500);
      ledcWriteTone(BUZZER_PIN_LEFT, 0);
      //state_button = 0x0;
      break;

    case RIGHT_SWITCH:
      Serial.printf("LEFT: %d  RIGHT: %d\n", CounterLeft, CounterRight);
      ledcWriteTone(BUZZER_PIN_RIGHT, 1000);
      delay(500);
      ledcWriteTone(BUZZER_PIN_RIGHT, 0);
      //state_button = 0x0;
      break;
  }

  state_button = 0x0;
}
*/
