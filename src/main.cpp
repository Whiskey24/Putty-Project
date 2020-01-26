#include <Arduino.h>
#include <StatusLEDs.h>
#include <log4arduino.h>
#include <pt.h>

void setup() {
  Serial.begin(57600);
  LOG_INIT(&Serial);
  LOG(".");
  LOG("Hello, waking up...");
  StatusLEDs::setup();
  StatusLEDs::setLEDStatus(CurrentLEDStatus::Running);
}

void loop() {
  StatusLEDs::protothreadLEDGreen();
  StatusLEDs::protothreadLEDRed();
}