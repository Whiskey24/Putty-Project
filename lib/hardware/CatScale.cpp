#include "statusLEDs.h"
#include <Arduino.h>
#include <hardwareConsts.h>
#include <log4arduino.h>
#include <pt.h>
#include <HX711.h>

HX711 *CatScale::catScale1;
HX711 *CatScale::catScale2;

void CatScale::setup() {
  LOG("CatScale setup started");

  LOG("CatScale setup completed");
}