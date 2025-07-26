// #include "gamepad.h"
#include "keyboard.h"
#include "lights.h"
#include <Arduino.h>

void setup() {
  Serial.begin(115200);

  for (int i = 0; i < NUM_BUTTONS; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }
  pinMode(L2_PIN, INPUT_PULLUP);
  pinMode(R2_PIN, INPUT_PULLUP);

  // Gamepad.begin();
  Keyboard.begin();
  USB.begin();

  xTaskCreate(lightsTask,   // Function to run
              "lightsTask", // Name
              1024,         // Stack size
              NULL,         // Parameters
              1,            // Priority
              NULL          // Task handle
  );
}

void loop() {
  // gamepadTask();
  keyboardTask();
}

