#include "Config.h"

unsigned long last_press_left_millis;
unsigned long last_press_right_millis;

uint8_t output_active = 0;
unsigned long output_start_time = 0;

void setup() {
  Serial.begin(115200);

  devices_setup();
  
  last_press_left_millis  = 0;
  last_press_right_millis = 0;

  servo_angle = 90;
  my_servo.write(servo_angle);

  Serial.println();
  Serial.println("Press buttons on GPIO 4 (←) or GPIO 1 (→)");
  Serial.println();
}


void loop() {

  //  If Left Side Was Press
  if (state_button & SWITCH_LEFT) {

    ledcWriteTone(BUZZER_PIN_RIGHT, 0);
    digitalWrite(LED_PIN_RIGHT, LED_OFF);

    ledcWriteTone(BUZZER_PIN_LEFT, BUZZER_FREQ_LEFT);
    digitalWrite(LED_PIN_LEFT, LED_ON);

    servo_angle = max( SERVO_MIN_ANGLE, 
                      servo_angle - SERVO_STEP_ANGLE);

    my_servo.write(servo_angle);

    output_active = SWITCH_LEFT;
    output_start_time = millis();

    state_button &= ~SWITCH_LEFT;
  }


  //  If Right Side Was Press
  if (state_button & SWITCH_RIGHT) {

    ledcWriteTone(BUZZER_PIN_LEFT, 0);
    digitalWrite(LED_PIN_LEFT, LED_OFF);

    ledcWriteTone(BUZZER_PIN_RIGHT, BUZZER_FREQ_RIGHT);
    digitalWrite(LED_PIN_RIGHT, LED_ON);

    servo_angle = min( SERVO_MAX_ANGLE,
                      servo_angle + SERVO_STEP_ANGLE);

    my_servo.write(servo_angle);

    output_active = SWITCH_RIGHT;
    output_start_time = millis();

    state_button &= ~SWITCH_LEFT;
  }


  if (output_active && 
      millis() - output_start_time >= TIMER_DELAY) {
    
    if (output_active == SWITCH_LEFT) {
      ledcWriteTone(BUZZER_PIN_LEFT, 0);
      digitalWrite(LED_PIN_LEFT, LED_OFF);
    }
    else if (output_active == SWITCH_RIGHT) {
      ledcWriteTone(BUZZER_PIN_RIGHT, 0);
      digitalWrite(LED_PIN_RIGHT, LED_OFF);
    }

  }

  output_active = 0;
}


/*
void loop() {

  //  If Left Side Was Press
  if (state_button & SWITCH_LEFT) {

    unsigned long current_time_left_millis = millis();
    
    if (current_time_left_millis - last_press_left_millis > TIMER_DELAY) {
      ledcWriteTone(BUZZER_PIN_LEFT, BUZZER_FREQ_LEFT);
      digitalWrite(LED_PIN_LEFT, LED_ON);
    }

    servo_angle = max( SERVO_MIN_ANGLE, servo_angle - SERVO_STEP_ANGLE);
    my_servo.write(servo_angle);
    
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

    servo_angle = min( SERVO_MAX_ANGLE, servo_angle + SERVO_STEP_ANGLE);
    my_servo.write(servo_angle);
    
    ledcWriteTone(BUZZER_PIN_RIGHT, 0);
    digitalWrite(LED_PIN_RIGHT, LED_OFF);
    state_button = 0x0;
    last_press_right_millis = current_time_right_millis;
  }

  //delay(1000);
}
*/