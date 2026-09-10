#include "Config.h"

volatile uint8_t state_button = 0;

Servo my_servo;
int servo_angle = 0;

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

  // SERVO
  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);
  my_servo.setPeriodHertz(50);
  my_servo.attach(SERVO_PIN, 500, 2400);
  delay(200);
  //servo_angle = 90;
  //my_servo.write(servo_angle);
}

void ARDUINO_ISR_ATTR Left_buttonISR() {
  state_button |= SWITCH_LEFT;
}

void ARDUINO_ISR_ATTR Right_buttonISR() {
  state_button |= SWITCH_RIGHT;
}
