#ifndef LED_H
#define LED_H
#include "pico/stdlib.h"

#ifndef LED_PIN 
#define RED_LED_PIN 0
#define GREEN_LED_PIN 1 
#define BLUE_LED_PIN 2 
#endif

void led_init();

#endif