#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_PIN_R = 28;
const int BTN_PIN_G = 26;
const int LED_PIN_R = 4;
const int LED_PIN_G = 6;

int main() {
  stdio_init_all();

  gpio_init(BTN_PIN_R);
  gpio_set_dir(BTN_PIN_R, GPIO_IN);
  gpio_pull_up(BTN_PIN_R);

  gpio_init(BTN_PIN_G);
  gpio_set_dir(BTN_PIN_G, GPIO_IN);
  gpio_pull_up(BTN_PIN_G);

  gpio_init(LED_PIN_R);
  gpio_set_dir(LED_PIN_R, GPIO_OUT);

  gpio_init(LED_PIN_G);
  gpio_set_dir(LED_PIN_G, GPIO_OUT);

  int on_off_G = 0;
  int on_off_R = 0;

  while (true) {
    if (!gpio_get(BTN_PIN_R)) {
      if (!on_off_R) {
        on_off_R = 1;
        gpio_put(LED_PIN_R, on_off_R);
        sleep_ms(250);
      } else {
        on_off_R = 0;
        gpio_put(LED_PIN_R, on_off_R);
        sleep_ms(250);
      }
      while (!gpio_get(BTN_PIN_R)) {
      };
    }

    if (!gpio_get(BTN_PIN_G)) {
      if (!on_off_G) {
        on_off_G = 1;
        gpio_put(LED_PIN_G, on_off_G);
        sleep_ms(250);
      } else {
        on_off_G = 0;
        gpio_put(LED_PIN_G, on_off_G);
        sleep_ms(250);
      }
      while (!gpio_get(BTN_PIN_G)) {
      };
    }

  }
}
