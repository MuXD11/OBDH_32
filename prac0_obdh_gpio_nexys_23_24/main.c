#include "leon3_ev_handling.h"
#include "leon3_hw_irqs.h"
#include "nexys_gpio_drv.h"

#include <stdio.h>

uint8_t current_led = 0;

uint8_t displays7seg_value[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };

//Clear displays values
void clear_displays7segs_values(void) {
	uint8_t i;
	for (i = 0; i < 8; i++)
		displays7seg_value[i] = 0;

}

//Define next value for displays
void next_displays7segs_values(void) {
	uint8_t end = 0;
	uint8_t index = 7;
	while (!end) {
		if (displays7seg_value[index] < 9) {
			displays7seg_value[index]++;
			end = 1;
		} else {
			displays7seg_value[index] = 0;
			if (0 == index) {
				clear_displays7segs_values();
				end = 1;
			} else {
				index--;
			}

		}
	}

}

void button_handler(void) {


	current_led++;
	if (10 == current_led)
		current_led = 0;

	next_displays7segs_values();
}

int main() {
	uint8_t i;
	uint8_t led = 0;
	uint8_t displays7seg_local_copy[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };

	printf("\nInit GPIO NEXYS EXAMPLE\n");

	nexys_srg_gpio_init_buttons_switches();

	nexys_srg_gpio_init_leds_7segs_displays();

	//Instalar como manejador del trap 0x83 la rutina
	// que habilita las interrupciones
	leon3_set_trap_handler(0x83, leon3_trap_handler_enable_irqs);

	//Instalar el manejador del trap que 0x83 la rutina
	// que deshabilita las interrupciones
	leon3_set_trap_handler(0x84, leon3_trap_handler_disable_irqs);

	//Deshabilitar las interrupciones
	leon3_sys_call_disable_irqs();

	//Enmascarar todas las interrupciones, sólo desenmascaremos aquellas que tenemos manejadas.
	leon3_mask_all_irqs();

	//Instalar la función button_handler como
	// manejador de usuario de la interrupción de nivel 4
	leon3_install_user_hw_irq_handler(4, button_handler);

	//Configura los 6 botones para que interrumpan al ser pulsados
	for (i = 0; i < 6; i++) {
		nexys_srg_gpio_config_button_irq(i, irq_active_low, irq_edge);
		nexys_srg_gpio_enable_button_irq(i);

	}

	//Enciende el primer LED
	nexys_srg_gpio_turn_on_led(current_led);

	//Desenmascarar la interrupción de nivel 4
	leon3_unmask_irq(4);

	//Habilitar las interrupciones
	leon3_sys_call_enable_irqs();

	printf("Pulsa Boton para incrementar cuenta\n");

	//Sacamos por los displays un incremento
	do {

		int first_digit = 0;

		//Valor de los displays
		for (i = 0; i < 8; i++) {
			if (displays7seg_local_copy[i] != 0)
				first_digit = 1;
			if (first_digit)
				nexys_srg_gpio_set_7seg_digit(i,
						displays7seg_local_copy[i]);
		}

		//Detecta botón pulsado
		if ((led) != current_led) {

			nexys_srg_gpio_turn_off_led(led);

			nexys_srg_gpio_turn_on_led(current_led);

			printf(".");
			led = current_led;
			//Inicio Sección Crítica entre IRQ 4 handler y main
			leon3_mask_irq(4);

			for (i = 0; i < 8; i++) {
				displays7seg_local_copy[i] = displays7seg_value[i];
			}
			//Fin Sección Crítica entre IRQ 4 handler y main
			leon3_unmask_irq(4);
		}

	} while (1);

	return 0;
}
