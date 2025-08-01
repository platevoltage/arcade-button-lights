#include "USB.h"
#include "USBHIDKeyboard.h"
#include <Arduino.h>

USBHIDKeyboard Keyboard;

#define BUTTON_PIN_0_P1 1
#define BUTTON_PIN_1_P1 2
#define BUTTON_PIN_2_P1 3
#define BUTTON_PIN_3_P1 4
#define BUTTON_PIN_4_P1 5
#define BUTTON_PIN_5_P1 6
#define BUTTON_PIN_6_P1 7
#define BUTTON_PIN_7_P1 8
// #define BUTTON_PIN_8_P1 9
// #define BUTTON_PIN_9_P1 10
#define L2_PIN_P1 11
#define R2_PIN_P1 12

#define BUTTON_PIN_0_P2 40
#define BUTTON_PIN_1_P2 39
#define BUTTON_PIN_2_P2 38
#define BUTTON_PIN_3_P2 37
#define BUTTON_PIN_4_P2 36
#define BUTTON_PIN_5_P2 34
#define BUTTON_PIN_6_P2 13
#define BUTTON_PIN_7_P2 14
// #define BUTTON_PIN_8_P2 9
// #define BUTTON_PIN_9_P2 10
#define L2_PIN_P2 21
#define R2_PIN_P2 17

#define _KEY_0_P1 'x'
#define _KEY_1_P1 'z'
#define _KEY_2_P1 's'
#define _KEY_3_P1 'a'
#define _KEY_4_P1 'q'
#define _KEY_5_P1 'w'
#define _KEY_6_P1 KEY_RIGHT_SHIFT
#define _KEY_7_P1 KEY_RETURN
#define _KEY_8_P1 '1'
#define _KEY_9_P1 '2'

#define _KEY_0_P2 't'
#define _KEY_1_P2 'y'
#define _KEY_2_P2 'u'
#define _KEY_3_P2 'i'
#define _KEY_4_P2 'o'
#define _KEY_5_P2 'f'
#define _KEY_6_P2 'g'
#define _KEY_7_P2 'j'
#define _KEY_8_P2 '3'
#define _KEY_9_P2 '4'

#define NUM_BUTTONS 20

const uint8_t buttonPins[NUM_BUTTONS] = {
    BUTTON_PIN_0_P1, BUTTON_PIN_1_P1, BUTTON_PIN_2_P1, BUTTON_PIN_3_P1,
    BUTTON_PIN_4_P1, BUTTON_PIN_5_P1, BUTTON_PIN_6_P1, BUTTON_PIN_7_P1,
    L2_PIN_P1,       R2_PIN_P1,       BUTTON_PIN_0_P2, BUTTON_PIN_1_P2,
    BUTTON_PIN_2_P2, BUTTON_PIN_3_P2, BUTTON_PIN_4_P2, BUTTON_PIN_5_P2,
    BUTTON_PIN_6_P2, BUTTON_PIN_7_P2, L2_PIN_P2,       R2_PIN_P2};

const uint8_t keys[NUM_BUTTONS] = {
    _KEY_0_P1, _KEY_1_P1, _KEY_2_P1, _KEY_3_P1, _KEY_4_P1, _KEY_5_P1, _KEY_6_P1,
    _KEY_7_P1, _KEY_8_P1, _KEY_9_P1, _KEY_0_P2, _KEY_1_P2, _KEY_2_P2, _KEY_3_P2,
    _KEY_4_P2, _KEY_5_P2, _KEY_6_P2, _KEY_7_P2, _KEY_8_P2, _KEY_9_P2,
};

void probeButton(uint8_t buttonPin, uint8_t buttonNumber) {
  if (!digitalRead(buttonPin))
    Keyboard.press(keys[buttonNumber]);
  else
    Keyboard.release(keys[buttonNumber]);
}

void keyboardTask(void *pvParameters) {
  while (1) {

    for (int i = 0; i < NUM_BUTTONS; i++) {
      probeButton(buttonPins[i], i);
    }
    vTaskDelay(1);
  }
}