#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define SERVO 12
#define PERIODO 20000 // Período do PWM em microsegundos

// Configuração do PWM
void setup_pwm(uint gpio) {
    gpio_set_function(gpio, GPIO_FUNC_PWM);
    uint slice = pwm_gpio_to_slice_num(gpio);
    pwm_set_clkdiv(slice, 64.0f); // Define o divisor de clock para 64
    pwm_set_wrap(slice, 39062);   // Define o valor máximo do contador PWM
    pwm_set_enabled(slice, true); // Habilita o PWM
}

// Função para controlar o servo motor
void servo_controler(uint gpio, uint ciclo) {
    uint slice = pwm_gpio_to_slice_num(gpio); // Obtém o slice do PWM
    uint level = (ciclo * 39062) / PERIODO;   // Calcula o nível de PWM correspondente
    pwm_set_chan_level(slice, PWM_CHAN_A, level); // Ajusta o nível do PWM na faixa do canal A
}

int main() {
    stdio_init_all();
    setup_pwm(SERVO);

    while (true) {
        
        servo_controler(SERVO, 2400);// Posição de 180° 
        sleep_ms(5000);

        
        servo_controler(SERVO, 1470);// Posição de 90° 
        sleep_ms(5000);

       
        servo_controler(SERVO, 500); // Posição de 0° 
        sleep_ms(5000);

        // Movimentação de 0° para 180°
        for (uint ciclo = 500; ciclo <= 2400; ciclo += 5) {
            servo_controler(SERVO, ciclo);
            sleep_ms(10);
        }

        // Movimentação de 180° para 0°
        for (uint ciclo = 2400; ciclo >= 500; ciclo -= 5) {
            servo_controler(SERVO, ciclo);
            sleep_ms(10);
        }

        // Movimentação de 0° para 180°
        for (uint ciclo = 500; ciclo <= 2400; ciclo += 5) {
            servo_controler(SERVO, ciclo);
            sleep_ms(10);
        }
    }
}
