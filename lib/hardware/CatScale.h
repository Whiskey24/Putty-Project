#pragma once
#include <HX711.h>

class CatScale
{
public:
  static void setup();
  static int protothreadCatScale();

private:
  static struct pt ptCatScale;
  static HX711 *catScale1;
  static HX711 *catScale2;
};