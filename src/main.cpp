// #include "gamepad.h"
#include "keyboard.h"
#include "lights.h"
#include <Arduino.h>

void setup() {
  Serial.begin(115200);
  Serial.setTxTimeoutMs(0);
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
  xTaskCreate(writeTask,   // Function to run
              "writeTask", // Name
              100000,      // Stack size
              NULL,        // Parameters
              1,           // Priority
              NULL         // Task handle
  );
}

void loop() {
  // gamepadTask();
  keyboardTask();
  // Serial.printf("Free heap: %d\n", ESP.getFreeHeap());
  // Serial.printf("Minimum free heap: %d\n", ESP.getMinFreeHeap());
  // Serial.printf("Maximum allocatable block: %d\n",
  //               heap_caps_get_largest_free_block(MALLOC_CAP_DEFAULT));
  Delay(1);
}
