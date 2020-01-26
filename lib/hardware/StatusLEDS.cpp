#include "statusLEDs.h"
#include "hardwareConsts.h"
#include <Arduino.h>
#include <pt.h>

// private static
pt StatusLEDs::ptLEDGreen;
pt StatusLEDs::ptLEDRed;
int StatusLEDs::milliSecondsOnGreen = 1000;
int StatusLEDs::milliSecondsOffGreen = 1000;
int StatusLEDs::milliSecondsOnRed = 0;
int StatusLEDs::milliSecondsOffRed = 2147483647;
// CurrentGreenStatus StatusLEDs::greenStatus = CurrentGreenStatus::Off;
// CurrentRedStatus StatusLEDs::redStatus = CurrentRedStatus::Off;
CurrentLEDStatus StatusLEDs::cLEDStatus = CurrentLEDStatus::Off;

void StatusLEDs::setup() {
  Serial.println("StatusLeds setup started");
  pinMode(UC_PIN_LED_GREEN, OUTPUT);
  pinMode(UC_PIN_LED_RED, OUTPUT);
  PT_INIT(&ptLEDGreen);
  PT_INIT(&ptLEDRed);
  Serial.println("StatusLeds setup completed");
}

int StatusLEDs::protothreadLEDGreen() {
  static unsigned long lastTimeBlinkGreen = 0;
  PT_BEGIN(&ptLEDGreen);

  while (1) {
    lastTimeBlinkGreen = millis();
    PT_WAIT_UNTIL(&ptLEDGreen, millis() - lastTimeBlinkGreen > milliSecondsOffGreen);
    digitalWrite(UC_PIN_LED_GREEN, HIGH);
    lastTimeBlinkGreen = millis();
    PT_WAIT_UNTIL(&ptLEDGreen, millis() - lastTimeBlinkGreen > milliSecondsOnGreen);
    digitalWrite(UC_PIN_LED_GREEN, LOW);
  }

  PT_END(&ptLEDGreen);
}

int StatusLEDs::protothreadLEDRed() {
  static unsigned long lastTimeBlinkRed = 0;
  PT_BEGIN(&ptLEDRed);

  while (1) {
    lastTimeBlinkRed = millis();
    PT_WAIT_UNTIL(&ptLEDRed, millis() - lastTimeBlinkRed > milliSecondsOffRed);
    digitalWrite(UC_PIN_LED_RED, HIGH);
    lastTimeBlinkRed = millis();
    PT_WAIT_UNTIL(&ptLEDRed, millis() - lastTimeBlinkRed > milliSecondsOnRed);
    digitalWrite(UC_PIN_LED_RED, LOW);
  }

  PT_END(&ptLEDRed);
};

void StatusLEDs::setLEDStatus(CurrentLEDStatus cLEDstatus) {
  switch (cLEDstatus) {
  case Off:
    milliSecondsOnGreen = 0;
    milliSecondsOffGreen = 2147483647;
    milliSecondsOnRed = 0;
    milliSecondsOffRed = 2147483647;
    break;
  case Booting:
    milliSecondsOnGreen = 1000;
    milliSecondsOffGreen = 1000;
    break;
  case Running:
    milliSecondsOnGreen = 3000;
    milliSecondsOffGreen = 1000;
    break;
  case Activity:
    milliSecondsOnGreen = 500;
    milliSecondsOffGreen = 500;
    break;
  case ErrorLight:
    milliSecondsOnRed = 1000;
    milliSecondsOffRed = 1000;
    break;
  case ErrorSevere:
    milliSecondsOnRed = 500;
    milliSecondsOffRed = 500;
    break;
  case ErrorReset:
    milliSecondsOnRed = 0;
    milliSecondsOffRed = 2147483647;
    break;
  }
}

/*

status lights for:
- nominal operation
- activity
- error light
- error severe

*/
