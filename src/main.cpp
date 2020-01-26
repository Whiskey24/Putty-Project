#include <Arduino.h>
#include <StatusLEDs.h>
#include <pt.h>

void setup() {
  StatusLEDs::setup();
  StatusLEDs::setLEDStatus(CurrentLEDStatus::Running);
}

void loop() {
  StatusLEDs::protothreadLEDGreen();
  StatusLEDs::protothreadLEDRed();
}