#pragma once
#include <pins_arduino.h>

/*
 * Status LEDs
 */
static const uint8_t UC_PIN_LED_GREEN = 12; // GPIO12, ADC2_5, TOUCH5, Physical 18
static const uint8_t UC_PIN_LED_RED = 14;   // GPIO14, ADC2_6, TOUCH6, Physical 17

/*
 * Cat scale HX711 with 2 load cells, LC1 and LC2
 */
static const uint8_t UC_PIN_CATSCALE_LC1_DT = 33;    // GPIO33, ADC1_5, TOUCH8, Physical 13
static const uint8_t UC_PIN_CATSCALE_LC1_SCK = 25;   // GPIO25, ADC2_8, DAC_1, Physical 14
static const uint8_t UC_PIN_CATSCALE_LC1_GAIN = 128; // Channel A
static const uint8_t UC_PIN_CATSCALE_LC2_DT = 33;    // GPIO33, ADC1_5, TOUCH8, Physical 13
static const uint8_t UC_PIN_CATSCALE_LC2_SCK = 25;   // GPIO25, ADC2_8, DAC_1, Physical 14
static const uint8_t UC_PIN_CATSCALE_LC2_GAIN = 32;  // Channel B