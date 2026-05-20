#include "esp_log.h"
#include <stdbool.h>
#include "rgb_led.h"
#include "delay.h"
#include "touchpad.h"

#define POLLING_PERIOD_MS 50
static const char *TAG = "MAIN";

void app_main(void)
{
    rgb_led_init();
    touchpad_init();

    bool last_state[TOUCHPAD_BUTTON_COUNT] = {false}; //todo el array en false 

    while (1) {
        for (uint8_t i = 0; i < TOUCHPAD_BUTTON_COUNT; i++) {
            bool pressed = touchpad_is_pressed(i);

            if (pressed && !last_state[i]) {
                ESP_LOGI(TAG, "Boton %d presionado", i);

                if (i == 0) {
                    rgb_led_set_color(255, 0, 0);//volumen up = rojo
                } else if (i == 1) {
                    rgb_led_off();//play/pause = apaga
                } else if (i == 2) {
                    rgb_led_set_color(0, 0, 255);//volumen down = azul
                } else if (i == 3) {
                    rgb_led_set_color(255, 255, 0);//record = amarillo
                } else if (i == 4) {
                    rgb_led_set_color(255, 0, 255);//camera = violeta (magenta)
                } else if (i == 5) {
                    rgb_led_set_color(0, 255, 0);//Network = verde
                }
            //rgb toma (uint8_t red, uint8_t green, uint8_t blue)
            }

            if (!pressed && last_state[i]) {
                ESP_LOGI(TAG, "Boton %d liberado", i);
            }

            last_state[i] = pressed;
        }

        delay_ms(POLLING_PERIOD_MS);
    }
}