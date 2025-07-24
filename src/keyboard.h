#include "USB.h"
#include "USBHIDKeyboard.h"
#include <Arduino.h>

USBHIDKeyboard Keyboard;

#define BUTTON_PIN_0 1
#define BUTTON_PIN_1 2
#define BUTTON_PIN_2 3
#define BUTTON_PIN_3 4
#define BUTTON_PIN_4 5
#define BUTTON_PIN_5 6
#define BUTTON_PIN_6 7
#define BUTTON_PIN_7 8
#define BUTTON_PIN_8 9
#define BUTTON_PIN_9 10
#define L2_PIN 11
#define R2_PIN 12

#define _KEY_0 'x'
#define _KEY_1 'z'
#define _KEY_2 's'
#define _KEY_3 'a'
#define _KEY_4 'q'
#define _KEY_5 'w'
#define _KEY_6 KEY_RIGHT_SHIFT
#define _KEY_7 KEY_RETURN
#define _KEY_8 '1'
#define _KEY_9 '2'

#define NUM_BUTTONS 10

const uint8_t buttonPins[NUM_BUTTONS] = {
    BUTTON_PIN_0, BUTTON_PIN_1, BUTTON_PIN_2, BUTTON_PIN_3, BUTTON_PIN_4,
    BUTTON_PIN_5, BUTTON_PIN_6, BUTTON_PIN_7, L2_PIN,       R2_PIN};

const uint8_t keys[NUM_BUTTONS] = {
    _KEY_0, _KEY_1, _KEY_2, _KEY_3, _KEY_4,
    _KEY_5, _KEY_6, _KEY_7, _KEY_8, _KEY_9,
};

void probeButton(uint8_t buttonPin, uint8_t buttonNumber) {
  if (!digitalRead(buttonPin))
    Keyboard.press(keys[buttonNumber]);
  else
    Keyboard.release(keys[buttonNumber]);
}

void keyboardTask() {
  for (int i = 0; i < NUM_BUTTONS; i++) {
    probeButton(buttonPins[i], i);
  }
}