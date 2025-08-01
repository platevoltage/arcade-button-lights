
#include <Adafruit_TLC5947.h>
#include <Arduino.h>
#include <ArduinoJson.h>
#include <FastLED.h>

#define NUM_TLC5947 3

#define NUM_BUTTONS 20

#define data 16
#define clock 18
#define latch 35

#define STEP 200

#define SELECT_P1 14
#define START_P1 15
#define TOP_1_P1 0
#define TOP_2_P1 1
#define TOP_3_P1 2
#define TOP_4_P1 3
#define BOTTOM_1_P1 4
#define BOTTOM_2_P1 5
#define BOTTOM_3_P1 6
#define BOTTOM_4_P1 7

#define SELECT_P2 12
#define START_P2 13
#define TOP_1_P2 16
#define TOP_2_P2 17
#define TOP_3_P2 18
#define TOP_4_P2 19
#define BOTTOM_1_P2 20
#define BOTTOM_2_P2 21
#define BOTTOM_3_P2 22
#define BOTTOM_4_P2 23

uint8_t buttons[NUM_BUTTONS] = {
    TOP_1_P1,    TOP_2_P1,    TOP_3_P1,    TOP_4_P1,  BOTTOM_1_P1,
    BOTTOM_2_P1, BOTTOM_3_P1, BOTTOM_4_P1, SELECT_P1, START_P1,
    TOP_1_P2,    TOP_2_P2,    TOP_3_P2,    TOP_4_P2,  BOTTOM_1_P2,
    BOTTOM_2_P2, BOTTOM_3_P2, BOTTOM_4_P2, SELECT_P2, START_P2};

String jsonString;
int r[NUM_BUTTONS], g[NUM_BUTTONS], b[NUM_BUTTONS] = {0};
int rTarget[NUM_BUTTONS], gTarget[NUM_BUTTONS], bTarget[NUM_BUTTONS] = {0};
Adafruit_TLC5947 tlc = Adafruit_TLC5947(NUM_TLC5947, clock, data, latch);

void Delay(int x) { vTaskDelay(pdMS_TO_TICKS(x)); }

void writeTask(void *pvParameters) {
  tlc.begin();

  while (1) {

    for (int i = 0; i < NUM_BUTTONS; i++) {
      float rGap = rTarget[i] - r[i];
      int ratio = abs(round(rGap * .1)) + 10;
      if (rGap >= ratio) {
        r[i] += ratio;
        // Serial.println(r[i]);
      } else if (rGap <= -ratio) {
        r[i] -= ratio;
        // Serial.println(r[i]);
      } else {
        r[i] = rTarget[i];
      }

      float gGap = gTarget[i] - g[i];
      ratio = abs(round(gGap * .1)) + 10;
      if (gGap >= ratio) {
        g[i] += ratio;
        // Serial.println(g[i]);
      } else if (gGap <= -ratio) {
        g[i] -= ratio;
        // Serial.println(g[i]);
      } else {
        g[i] = gTarget[i];
      }

      float bGap = bTarget[i] - b[i];
      ratio = abs(round(bGap * .1)) + 10;
      if (bGap >= ratio) {
        b[i] += ratio;
        // Serial.println(b[i]);
      } else if (bGap <= -ratio) {
        b[i] -= ratio;
        // Serial.println(b[i]);
      } else {
        b[i] = bTarget[i];
      }

      tlc.setLED(buttons[i], r[i], g[i], b[i]);
      // tlc.setLED(i >= 8 ? i + 4 : i + 16, r[i], g[i], b[i]);
    }
    tlc.write();
    Delay(10);
  }
}

void go(TimerHandle_t xTimer) {
  StaticJsonDocument<512> doc;
  // Only try to parse if we actually got something

  DeserializationError error = deserializeJson(doc, jsonString);
  if (error) {
    Serial.println("JSON parse error");
    return; // Don't return or break the task
  }

  for (int i = 0; i < NUM_BUTTONS; i++) {
    String key = "button" + String(i + 1);
    const char *hex = doc[key];

    if (!hex) {
      String newKey = "button" + String(i + 1 - NUM_BUTTONS / 2);
      hex = doc[newKey];
    }

    if (hex && strlen(hex) >= 6) {
      String hexStr(hex);
      int r8 = strtol(hexStr.substring(0, 2).c_str(), nullptr, 16);
      int g8 = strtol(hexStr.substring(2, 4).c_str(), nullptr, 16);
      int b8 = strtol(hexStr.substring(4, 6).c_str(), nullptr, 16);

      rTarget[i] = (r8 * 4095 + 127) / 255;
      gTarget[i] = (g8 * 4095 + 127) / 255;
      bTarget[i] = (b8 * 4095 + 127) / 255;
    } else {
      rTarget[i] = gTarget[i] = bTarget[i] = 0;
    }
  }
}

void lightsTask(void *pvParameters) {
  // StaticJsonDocument<512> doc;
  Serial.setTimeout(10); // Don't block for long
  while (1) {
    if (Serial.available()) {
      jsonString = Serial.readStringUntil('\n');
      Serial.println(jsonString);

      for (int i = 0; i < NUM_BUTTONS; i++) {
        rTarget[i] = gTarget[i] = bTarget[i] = 0;
      }

      TimerHandle_t timeout =
          xTimerCreate("Timeout", pdMS_TO_TICKS(400), pdFALSE, NULL, go);
      xTimerStart(timeout, 0);
    }

    vTaskDelay(1); // Yield to FreeRTOS scheduler
  }
}
