#include "Config.h"

unsigned long last_press_left_millis;

void setup() {
  Serial.begin(115200);

  devices_setup();
  last_press_left_millis = 0;
  Serial.println();
  Serial.println("Press the button on GPIO 4");
  Serial.println();
}

void loop() {
      
  if ( state_button & SWITCH){
    unsigned long current_time_left_millis = millis();

    if (current_time_left_millis - last_press_left_millis > TIMER_DELAY) {
      ledcWriteTone(BUZZER_PIN, BUZZER_FREQ);
      digitalWrite(LED_PIN, LED_ON);
    }
    
    ledcWriteTone(BUZZER_PIN, 0);
    digitalWrite(LED_PIN, LED_OFF);
    state_button = 0;
    last_press_left_millis = current_time_left_millis;
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
