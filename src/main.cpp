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
  // pinMode(L2_PIN, INPUT_PULLUP);
  // pinMode(R2_PIN, INPUT_PULLUP);

  Keyboard.begin();
  USB.begin();

  // Gamepad.begin();
  // Keyboard.begin();
  // USB.begin();

  xTaskCreatePinnedToCore(keyboardTask,   // Function to run
                          "keyboardTask", // Name
                          4096,           // Stack size
                          NULL,           // Parameters
                          1,              // Priority
                          NULL,           // Task handle
                          0);
  xTaskCreatePinnedToCore(lightsTask,   // Function to run
                          "lightsTask", // Name
                          4096,         // Stack size
                          NULL,         // Parameters
                          1,            // Priority
                          NULL,         // Task handle,
                          1);
  xTaskCreatePinnedToCore(writeTask,   // Function to run
                          "writeTask", // Name
                          4096,        // Stack size
                          NULL,        // Parameters
                          1,           // Priority
                          NULL,        // Task handle
                          1);
}

void loop() {
  // gamepadTask();
  // keyboardTask();
  // Delay(10); // appears to solve crash
  // Serial.printf("Free heap: %d\n", ESP.getFrew2eHeap());
  // Serial.printf("Minimum free heap: %d\n", ESP.getMinFreeHeap());
  // Serial.printf("Maximum allocatable block: %d\n",
  //               heap_caps_get_largest_free_block(MALLOC_CAP_DEFAULT));
}
