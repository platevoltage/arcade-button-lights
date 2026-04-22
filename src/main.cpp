// #include "gamepad.h"
#include "keyboard.h"
#include "lights.h"
#include <Arduino.h>

char jsonBuffer[512];
void lightsTask(void *pvParameters) {

  Serial.setTimeout(10);

  while (1) {

    int len = Serial.readBytesUntil('\n', jsonBuffer, sizeof(jsonBuffer) - 1);

    if (len > 0) {

      jsonBuffer[len] = '\0';
      // Serial.println(len);
      if (jsonBuffer[0] == '{') {
        // parse later
        for (int i = 0; i < NUM_BUTTONS; i++) {
          rTarget[i] = gTarget[i] = bTarget[i] = 0;
        }
        jsonString = String(jsonBuffer);
        go(NULL);
      } else {
        typeKey(jsonBuffer[0], KEY_LEFT_SHIFT);
      }
    }

    vTaskDelay(pdMS_TO_TICKS(10));
  }
}

// char jsonBuffer[512];

// void lightsTask(void *pvParameters) {

//   Serial.setTimeout(10);

//   while (1) {

//     if (Serial.available()) {

//       int len = Serial.readBytesUntil('\n', jsonBuffer, sizeof(jsonBuffer) -
//       1); jsonBuffer[len] = '\0';

//       if (len == 0)
//         continue;

//       Serial.println(jsonBuffer);

//       if (jsonBuffer[0] == '{') {

//         // parse JSON here

//       } else {

//         typeKey(jsonBuffer[0], KEY_LEFT_SHIFT);
//         vTaskDelay(pdMS_TO_TICKS(500));
//       }

//       while (Serial.available())
//         Serial.read();
//     }

//     vTaskDelay(pdMS_TO_TICKS(10));
//   }
// }

// void lightsTask(void *pvParameters) {
//   Serial.setTimeout(10); // Don't block for long
//   go(NULL);
//   while (1) {
//     if (Serial.available()) {
//       jsonString = Serial.readStringUntil('\n');
//       jsonString.trim();
//       if (jsonString.length() == 0)
//         continue;
//       Serial.println(jsonString);

//       if (jsonString[0] == '{') {

//         // for (int i = 0; i < NUM_BUTTONS; i++) {
//         //   rTarget[i] = gTarget[i] = bTarget[i] = 0;
//         // }

//         // TimerHandle_t timeout =
//         //     xTimerCreate("Timeout", pdMS_TO_TICKS(400), pdFALSE, NULL,
//         go);
//         // xTimerStart(timeout, 0);

//       } else {
//         typeKey(jsonString[0], KEY_LEFT_SHIFT);
//         vTaskDelay(pdMS_TO_TICKS(500));
//       }
//       while (Serial.available())
//         Serial.read();
//     }

//     vTaskDelay(pdMS_TO_TICKS(10));
//   }
// }

void setup() {
  Serial.begin(115200);
  Serial.setTxTimeoutMs(0);
  tlc.begin();
  for (int i = 0; i < NUM_BUTTONS; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
    tlc.setLED(i, 0, 0, 0);
  }
  tlc.write();
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
  // xTaskCreate(lightsTask,   // Function to run
  //             "lightsTask", // Name
  //             10000,        // Stack size
  //             NULL,         // Parameters
  //             1,            // Priority
  //             NULL);
  // xTaskCreatePinnedToCore(writeTask,   // Function to run
  //                         "writeTask", // Name
  //                         4096,        // Stack size
  //                         NULL,        // Parameters
  //                         1,           // Priority
  //                         NULL,        // Task handle
  //                         1);
}

void loop() {
  lightsTask(NULL);
  // gamepadTask();
  // keyboardTask();
  // Delay(10); // appears to solve crash
  // Serial.printf("Free heap: %d\n", ESP.getFrew2eHeap());
  // Serial.printf("Minimum free heap: %d\n", ESP.getMinFreeHeap());
  // Serial.printf("Maximum allocatable block: %d\n",
  //               heap_caps_get_largest_free_block(MALLOC_CAP_DEFAULT));
}
