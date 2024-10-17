#include "led.h"
#include <stdio.h>

void led_init()
{
    gpio_init(RED_LED_PIN);
    gpio_set_dir(RED_LED_PIN,GPIO_OUT);
    gpio_init(GREEN_LED_PIN);
    gpio_set_dir(GREEN_LED_PIN,GPIO_OUT);
    gpio_init(BLUE_LED_PIN);
    gpio_set_dir(BLUE_LED_PIN,GPIO_OUT);
}


int main()
{
    stdio_init_all();

    led_init();


    // Intialize all leds to be turned off
    gpio_put(BLUE_LED_PIN,1);
    gpio_put(RED_LED_PIN,0);
    gpio_put(GREEN_LED_PIN,0);
    while (true) {
        // Wait for 5 seconds before starting to turn on the leds
        sleep_ms(5000);
        // Turn on the red LED for 1 second
        gpio_put(RED_LED_PIN,1);
        sleep_ms(1000);
        // Turn on the red LED off and the green LED on for 1 second
        gpio_put(RED_LED_PIN,0);
        gpio_put(GREEN_LED_PIN,1);
        sleep_ms(1000);
        // Turn on the green LED off and the blue LED on for 1 second
        // Since the blue LED is negative logic, we set it on 0 instead of 1
        gpio_put(GREEN_LED_PIN,0);
        gpio_put(BLUE_LED_PIN,0);
        sleep_ms(1000);
        // Turn on all 3 LEDS for 2 seconds
        gpio_put(BLUE_LED_PIN,0);
        gpio_put(RED_LED_PIN,1);
        gpio_put(GREEN_LED_PIN,1);
        sleep_ms(2000);
        // Turn off all 3 LEDS and repeat the cycle
        gpio_put(BLUE_LED_PIN,1);
        gpio_put(RED_LED_PIN,0);
        gpio_put(GREEN_LED_PIN,0);
    }
}

