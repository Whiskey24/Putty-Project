#include "statusLEDs.h"
#include <Arduino.h>
#include <hardwareConsts.h>
#include <log4arduino.h>
#include <pt.h>

// private static
pt StatusLEDs::ptLEDGreen;
pt StatusLEDs::ptLEDRed;
int StatusLEDs::milliSecondsOnGreen = 1000;
int StatusLEDs::milliSecondsOffGreen = 1000;
int StatusLEDs::milliSecondsOnRed = 0;
int StatusLEDs::milliSecondsOffRed = 2147483647;
CurrentLEDStatus StatusLEDs::cLEDStatus = CurrentLEDStatus::Off;

void StatusLEDs::setup() {
  LOG("StatusLEDs setup started");
  pinMode(UC_PIN_LED_GREEN, OUTPUT);
  pinMode(UC_PIN_LED_RED, OUTPUT);
  PT_INIT(&ptLEDGreen);
  PT_INIT(&ptLEDRed);
  LOG("StatusLEDs setup completed");
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
    LOG("Setting statusLEDs status to Off");
    milliSecondsOnGreen = 0;
    milliSecondsOffGreen = 2147483647;
    milliSecondsOnRed = 0;
    milliSecondsOffRed = 2147483647;
    break;
  case Booting:
    LOG("Setting statusLEDs status to Booting");
    milliSecondsOnGreen = 200;
    milliSecondsOffGreen = 200;
    break;
  case Running:
    LOG("Setting statusLEDs status to Running");
    milliSecondsOnGreen = 3000;
    milliSecondsOffGreen = 1000;
    break;
  case Activity:
    LOG("Setting statusLEDs status to Activity");
    milliSecondsOnGreen = 500;
    milliSecondsOffGreen = 500;
    break;
  case ErrorLight:
    LOG("Setting statusLEDs status to Light Error");
    milliSecondsOnRed = 1000;
    milliSecondsOffRed = 1000;
    break;
  case ErrorSevere:
    LOG("Setting statusLEDs status to Severe Error");
    milliSecondsOnRed = 500;
    milliSecondsOffRed = 500;
    break;
  case ErrorReset:
    milliSecondsOnRed = 0;
    milliSecondsOffRed = 2147483647;
    break;
  }
}