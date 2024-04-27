#include <Arduino.h>
#define SensorPIN 36

bool var = false;
int long lastDebounceTime = 0; 
int long debounceDelay = 100; 
int interruptCount = 0;

void IRAM_ATTR sens_interruption () {
  int long currentMillis = millis();
  if (currentMillis - lastDebounceTime >= debounceDelay) {
    var = true;
    interruptCount++; 
  }

  lastDebounceTime = currentMillis;
}

void setup() {
  Serial.begin(9600);
  attachInterrupt(SensorPIN, sens_interruption, RISING);
}

void loop() {
  if (var == true) {
    Serial.print("INTERRUPT: ");
    Serial.println(interruptCount);
    var = false;
  }
}
