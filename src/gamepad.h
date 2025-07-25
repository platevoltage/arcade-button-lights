#include "USB.h"
#include "USBHIDGamepad.h"
#include <Arduino.h>

USBHIDGamepad Gamepad;

#define BUTTON_PIN_0 1 // A
#define BUTTON_PIN_1 2 // B
#define BUTTON_PIN_2 3 // X
#define BUTTON_PIN_3 4 // Y
#define BUTTON_PIN_4 5 // L
#define BUTTON_PIN_5 6 // R
#define BUTTON_PIN_6 7 // Select
#define BUTTON_PIN_7 8 // Start
#define BUTTON_PIN_8 9
#define BUTTON_PIN_9 10

#define NUM_BUTTONS 10

const uint8_t buttonPins[NUM_BUTTONS] = {
    BUTTON_PIN_0, BUTTON_PIN_1, BUTTON_PIN_2, BUTTON_PIN_3, BUTTON_PIN_4,
    BUTTON_PIN_5, BUTTON_PIN_6, BUTTON_PIN_7, BUTTON_PIN_8, BUTTON_PIN_9};

#define L2_PIN 11 // L2
#define R2_PIN 12 // R2

void probeButton(uint8_t buttonPin, uint8_t buttonNumber) {
  if (!digitalRead(buttonPin)) {

    Gamepad.pressButton(buttonNumber);

  } else
    Gamepad.releaseButton(buttonNumber);
}

int8_t z = 0;
int8_t rZ = 0;
void probeTriggers() {
  if (!digitalRead(L2_PIN))
    z = 127;
  else
    z = -128;

  if (!digitalRead(R2_PIN))
    rZ = 127;
  else
    rZ = -128;
  // This looks all wrong because the Library has a mistake. right and left
  // Triggers are mapped wrong.
  Gamepad.rightStick(z, rZ);
}

void gamepadTask() {
  for (int i = 0; i < NUM_BUTTONS; i++) {
    probeButton(buttonPins[i], i);
  }
  probeTriggers();
}