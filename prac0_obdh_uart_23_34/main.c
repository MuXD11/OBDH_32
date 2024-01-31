#include "leon3_ev_handling.h"
#include "leon3_hw_irqs.h"
#include "leon3_uart.h"


#include <stdio.h>

uint32_t rx_byte_counter = 0;


void uart_rx_handler(void) {

	leon3_getchar(); //Leo el caracter para vaciar el buffer
	rx_byte_counter++;
}

int main() {

	uint8_t byte_counter=0;
	//a

	printf("\nInit UART Example\n");

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


	leon3_install_user_hw_irq_handler(2, uart_rx_handler);

	//Configuro UART para disparar interrupciones al recibir un byte
	leon3_uart_ctrl_rx_irq_enable();
	leon3_uart_ctrl_rx_enable();

	//Desenmascarar la interrupción de nivel 2
	leon3_unmask_irq(2);


	//Habilitar las interrupciones
	leon3_sys_call_enable_irqs();

	//Sacamos por los displays un incremento
	do {


		//Detecta botón pulsado
		if((byte_counter)!=rx_byte_counter){
			printf(".");

			//Inicio Sección Crítica entre IRQ 2 handler y main
			leon3_mask_irq(2);
			byte_counter=rx_byte_counter;
			//Fin Sección Crítica entre IRQ 2 handler y main
			leon3_unmask_irq(2);

		}


	} while (1);

	return 0;
}
