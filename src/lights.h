
#include <Adafruit_TLC5947.h>
#include <Arduino.h>
#include <ArduinoJson.h>
#include <FastLED.h>

#define NUM_TLC5947 2

#define data 16
#define clock 18
#define latch 35

#define STEP 20

StaticJsonDocument<512> doc;

int r[10], g[10], b[10] = {0};
int rTarget[10], gTarget[10], bTarget[10] = {0};
Adafruit_TLC5947 tlc = Adafruit_TLC5947(NUM_TLC5947, clock, data, latch);

void Delay(int x) { vTaskDelay(pdMS_TO_TICKS(x)); }

void writeTask(void *pvParameters) {
  tlc.begin();

  while (1) {
    // for (int i = 0; i < 10; i++) {
    //   Serial.print(rTarget[i]);
    //   Serial.print(", ");
    //   Serial.print(gTarget[i]);
    //   Serial.print(", ");
    //   Serial.println(bTarget[i]);
    // }
    for (int i = 0; i < 10; i++) {
      // if (r[i] < rTarget[i])
      //   r[i]++;
      // else if (r[i] > rTarget[i])
      //   r[i]--;
      // if (g[i] < gTarget[i])
      //   g[i]++;
      // else if (g[i] > gTarget[i])
      //   g[i]--;
      // if (b[i] < bTarget[i])
      //   b[i]++;
      // else if (b[i] > bTarget[i])
      //   b[i]--;
      int rGap = rTarget[i] - r[i];
      if (rGap >= STEP) {
        r[i] += STEP;
      } else if (rGap <= -STEP) {
        r[i] -= STEP;
      } else {
        r[i] = rTarget[i];
      }

      int gGap = gTarget[i] - g[i];
      if (gGap >= STEP) {
        g[i] += STEP;
      } else if (gGap <= -STEP) {
        g[i] -= STEP;
      } else {
        g[i] = gTarget[i];
      }

      int bGap = bTarget[i] - b[i];
      if (bGap >= STEP) {
        b[i] += STEP;
      } else if (bGap <= -STEP) {
        b[i] -= STEP;
      } else {
        b[i] = bTarget[i];
      }

      tlc.setLED(i >= 8 ? i + 6 : i, r[i], g[i], b[i]);
    }
    tlc.write();
    Delay(10);
  }
}

void lightsTask(void *pvParameters) {
  while (1) {
    if (Serial.available()) {

      String jsonString = Serial.readStringUntil('\n'); // Wait for full line

      DeserializationError error = deserializeJson(doc, jsonString);
      if (error) {
        Serial.println("JSON parse error");
        return;
      }

      for (int i = 0; i < 10; i++) {
        String key = "button" + String(i + 1);
        const char *hex = doc[key];

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
      // Serial.flush();
    }
  }
}