#pragma once

enum CurrentLEDStatus
{
  Off = 1,
  Booting,
  Running,
  Activity,
  ErrorLight,  // light error occurred
  ErrorSevere, // severe error occurred
  ErrorReset
};

class StatusLEDs
{
public:
  static void setup();
  static int protothreadLEDGreen();
  static int protothreadLEDRed();
  static void setLEDStatus(CurrentLEDStatus cLEDStatus);

private:
  StatusLEDs(); // pure static madness
  static struct pt ptLEDGreen, ptLEDRed;
  static int milliSecondsOnGreen, milliSecondsOffGreen;
  static int milliSecondsOnRed, milliSecondsOffRed;
  static CurrentLEDStatus cLEDStatus;
};
