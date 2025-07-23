#include "lights.h"
#include <Arduino.h>

void setup() {
  Serial.begin(115200);
  Serial.println("TLC5947 test");
  tlc.begin();
  if (oe >= 0) {
    pinMode(oe, OUTPUT);
    digitalWrite(oe, LOW);
  }

  xTaskCreate(lightsTask,   // Function to run
              "lightsTask", // Name
              1024,         // Stack size
              NULL,         // Parameters
              1,            // Priority
              NULL          // Task handle
  );
}

void loop() {}
