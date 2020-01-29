#include "CatScale.h"
#include <Arduino.h>
#include <hardwareConsts.h>
#include <log4arduino.h>
#include <pt.h>

// private static
pt CatScale::ptCatScale;

HX711 *CatScale::catScale1;
HX711 *CatScale::catScale2;

void CatScale::setup() {
  LOG("CatScale setup started");
  catScale1 = new HX711();
  catScale2 = new HX711();

  catScale1->begin(UC_PIN_CATSCALE_LC1_DT, UC_PIN_CATSCALE_LC1_SCK, UC_PIN_CATSCALE_LC1_GAIN);
  catScale2->begin(UC_PIN_CATSCALE_LC2_DT, UC_PIN_CATSCALE_LC2_SCK, UC_PIN_CATSCALE_LC2_GAIN);

  LOG("CatScale setup completed");
};

int CatScale::protothreadCatScale() {
  PT_BEGIN(&ptCatScale);

  while (1) {
  }

  PT_END(&ptCatScale);
}
