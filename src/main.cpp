#include <Adafruit_TLC5947.h>
#include <Arduino.h>
#include <FastLED.h>

// How many boards do you have chained?
#define NUM_TLC5947 2

#define data 16
#define clock 18
#define latch 35
#define oe -1 // set to -1 to not use the enable pin (its optional)

Adafruit_TLC5947 tlc = Adafruit_TLC5947(NUM_TLC5947, clock, data, latch);

void setup() {
  Serial.begin(115200);
  Serial.println("TLC5947 test");
  tlc.begin();
  if (oe >= 0) {
    pinMode(oe, OUTPUT);
    digitalWrite(oe, LOW);
  }
}

// Fill the dots one after the other with a color
void colorWipe(uint16_t r, uint16_t g, uint16_t b, uint8_t wait) {
  for (uint16_t i = 0; i < 8 * NUM_TLC5947; i++) {
    tlc.setLED(i, r, g, b);
    tlc.write();
    delay(wait);
  }
}

// Input a value 0 to 4095 to get a color value.
// The colours are a transition r - g - b - back to r.
void Wheel(uint8_t ledn, uint16_t WheelPos) {
  if (WheelPos < 1365) {
    tlc.setLED(ledn, 3 * WheelPos, 4095 - 3 * WheelPos, 0);
  } else if (WheelPos < 2731) {
    WheelPos -= 1365;
    tlc.setLED(ledn, 4095 - 3 * WheelPos, 0, 3 * WheelPos);
  } else {
    WheelPos -= 2731;
    tlc.setLED(ledn, 0, 3 * WheelPos, 4095 - 3 * WheelPos);
  }
}
// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint32_t i, j;

  for (j = 0; j < 4096; j++) { // 1 cycle of all colors on wheel
    for (i = 0; i < 8 * NUM_TLC5947; i++) {
      Wheel(i, ((i * 4096 / (8 * NUM_TLC5947)) + j) & 4095);
    }
    tlc.write();
    delay(wait);
  }
}

void neogeo() {
  tlc.setLED(0, 4095, 4095, 0);
  tlc.write();
  delay(100);
  tlc.setLED(1, 0, 4095, 0);
  tlc.write();
  delay(100);
  tlc.setLED(2, 0, 0, 4095);
  tlc.write();
  delay(100);
  tlc.setLED(3, 0, 0, 0);
  tlc.setLED(4, 4095, 0, 0);
  tlc.write();
  delay(100);
  tlc.setLED(5, 0, 0, 0);
  tlc.setLED(6, 0, 0, 0);
  tlc.setLED(7, 0, 0, 0);
}

void nes() {
  tlc.setLED(0, 0, 0, 0);
  tlc.setLED(1, 0, 0, 0);
  tlc.setLED(2, 0, 0, 0);
  tlc.setLED(3, 0, 0, 0);
  tlc.setLED(4, 4095, 0, 0);
  tlc.write();
  delay(100);
  tlc.setLED(5, 4095, 0, 0);
  tlc.write();
  delay(100);
  tlc.setLED(6, 0, 0, 0);
  tlc.setLED(7, 0, 0, 0);
}

void snes() {
  tlc.setLED(0, 4095, 10000, 4095);
  tlc.write();
  delay(100);
  tlc.setLED(1, 4095, 10000, 4095);
  tlc.write();
  delay(100);
  tlc.setLED(2, 500, 500, 500);
  tlc.write();
  delay(100);
  tlc.setLED(3, 500, 500, 500);
  tlc.write();
  delay(100);
  tlc.setLED(4, 500, 0, 3000);
  tlc.write();
  delay(100);
  tlc.setLED(5, 500, 0, 3000);
  tlc.write();
  delay(100);
  tlc.setLED(6, 0, 0, 0);
  tlc.setLED(7, 0, 0, 0);
}

void superFamicom() {
  tlc.setLED(0, 0, 4095, 0);
  tlc.write();
  delay(100);
  tlc.setLED(1, 0, 0, 4095);
  tlc.write();
  delay(100);
  tlc.setLED(2, 500, 500, 500);
  tlc.write();
  delay(100);
  tlc.setLED(3, 500, 500, 500);
  tlc.write();
  delay(100);
  tlc.setLED(4, 4095, 4095, 0);
  tlc.write();
  delay(100);
  tlc.setLED(5, 4095, 0, 0);
  tlc.write();
  delay(100);
  tlc.setLED(6, 0, 0, 0);
  tlc.setLED(7, 0, 0, 0);
}

void segaGenesis() {
  tlc.setLED(0, 500, 500, 500);
  tlc.write();
  delay(100);
  tlc.setLED(1, 500, 500, 500);
  tlc.write();
  delay(100);
  tlc.setLED(2, 500, 500, 500);
  tlc.write();
  delay(100);
  tlc.setLED(3, 0, 0, 0);
  tlc.setLED(4, 4095, 0, 0);
  tlc.write();
  delay(100);
  tlc.setLED(5, 4095, 0, 0);
  tlc.write();
  delay(100);
  tlc.setLED(6, 4095, 0, 0);
  tlc.write();
  delay(100);
  tlc.setLED(7, 0, 0, 0);
}

void n64() {
  tlc.setLED(0, 0, 4095, 0);
  tlc.write();
  delay(100);
  tlc.setLED(1, 4095, 2000, 0);
  tlc.write();
  delay(100);
  tlc.setLED(2, 4095, 2000, 0);
  tlc.write();
  delay(100);
  tlc.setLED(3, 500, 500, 500);
  tlc.write();
  delay(100);
  tlc.setLED(4, 0, 0, 4095);
  tlc.write();
  delay(100);
  tlc.setLED(5, 4095, 2000, 0);
  tlc.write();
  delay(100);
  tlc.setLED(6, 4095, 2000, 0);
  tlc.write();
  delay(100);
  tlc.setLED(7, 500, 500, 500);
  tlc.write();
  delay(100);
}

void playstation() {
  tlc.setLED(0, 4095, 10000, 2000);
  tlc.write();
  delay(100);
  tlc.setLED(1, 10000, 4095, 10000);
  tlc.write();
  delay(100);
  tlc.setLED(2, 500, 500, 500);
  tlc.write();
  delay(100);
  tlc.setLED(3, 500, 500, 500);
  tlc.write();
  delay(100);
  tlc.setLED(4, 10000, 10000, 4095);
  tlc.write();
  delay(100);
  tlc.setLED(5, 4095, 100, 100);
  tlc.write();
  delay(100);
  tlc.setLED(6, 500, 500, 500);
  tlc.write();
  delay(100);
  tlc.setLED(7, 500, 500, 500);
  tlc.write();
  delay(100);
}

void ring(int r[10], int g[10], int b[10]) {
  for (int k = 0; k < 2; k++) {
    for (int j = 0; j < 8; j++) {
      for (int i = 0; i < 8; i++) {
        tlc.setLED(i, 0, 0, 0);
      }
      int _j = j > 3 ? 11 - j : j;
      tlc.setLED(_j, r[_j], g[_j], b[_j]);
      tlc.write();
      delay(100);
    }
  }
}

// void fadeIn(int r[10], int g[10], int b[10]) {
//   for (int j = 100; j > 0; j--) {
//     for (int i = 0; i < 10; i++) {
//       tlc.setLED(i >= 8 ? i + 6 : i, r[i] / j, g[i] / j, b[i] / j);
//     }
//     delay(5);
//     tlc.write();
//   }
// }

void fadeIn(int r[10], int g[10], int b[10], uint8_t amount = 255,
            uint16_t speed = 500, int exponent = 2) {
  for (int j = speed; j > speed - speed * ((float)amount / 255.0); j--) {
    float fadeRatio =
        pow((speed - j) / (float)speed, exponent); // Cubic ease-in

    for (int i = 0; i < 10; i++) {
      int rr = r[i] * fadeRatio;
      int gg = g[i] * fadeRatio;
      int bb = b[i] * fadeRatio;
      tlc.setLED(i >= 8 ? i + 6 : i, rr, gg, bb);
    }

    tlc.write();
    delay(5);
  }
}

void fadeOut(int r[10], int g[10], int b[10], uint8_t amount = 255,
             uint16_t speed = 500, int exponent = 2) {

  int steps = (float)speed * ((float)amount / 255.0);

  for (int j = steps; j > 0; j--) {
    float fadeRatio =
        pow(j / (float)speed, exponent); // Cubic or other power fade

    for (int i = 0; i < 10; i++) {
      int rr = r[i] * fadeRatio;
      int gg = g[i] * fadeRatio;
      int bb = b[i] * fadeRatio;
      tlc.setLED(i >= 8 ? i + 6 : i, rr, gg, bb);
    }

    tlc.write();
    delay(5);
  }
}

void loop() {
  if (Serial.available()) {
    int r[10], g[10], b[10];
    if (Serial.read() == '#') {
      for (int i = 0; i < 10; i++) {
        r[i] = Serial.parseInt();
        g[i] = Serial.parseInt();
        b[i] = Serial.parseInt();
      }
    }
    Serial.flush();
    while (Serial.available())
      Serial.read();

    // ring(r, g, b);
    // fadeIn(r, g, b, 255, 500, 2);
    // fadeOut(r, g, b, 255, 500, 2);
    fadeIn(r, g, b, 100, 1500, 3);
    fadeOut(r, g, b, 100, 1500, 3);
    // fadeIn(r, g, b, 255, 500, 4);
    // fadeOut(r, g, b, 255, 500, 4);
    // fadeIn(r, g, b, 20, 1000, 3);
    // fadeOut(r, g, b, 20, 1000, 3);
    // fadeIn(r, g, b, 80, 1000, 4);
    // fadeOut(r, g, b, 80, 1000, 4);
  }
}