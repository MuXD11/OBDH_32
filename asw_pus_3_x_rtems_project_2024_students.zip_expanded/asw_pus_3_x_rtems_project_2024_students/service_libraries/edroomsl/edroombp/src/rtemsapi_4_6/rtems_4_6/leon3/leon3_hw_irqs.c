/*
 * leon_irqs.c
 *
 *  Created on: Feb 28, 2013
 *      Author: user
 */
#include "public/basic_types.h"
#include "edroombp_swr/rtemsapi_4_6/rtems_4_6/leon3/leon3_hw_irqs.h"

//Mejora:
//Utilizad estos punteros para acceder a los registros
//Use these pointers to manage the IRQ CTRL Registers
uint32_t * LEON3_ICLEAR =  (uint32_t *) (0x80000000 + 0x20C);
uint32_t * LEON3_IMASK =  (uint32_t *) (0x80000000 + 0x240);
uint32_t * LEON3_IFORCE =  (uint32_t *) (0x80000000 + 0x208);

/** Pone a uno el bit correspondiente al irq level para hacer el clear de la pending irq .*/
/** Set bit of the irq level to clear the pending irq .*/
uint8_t leon3_clear_irq (uint8_t irq_level) {
	uint8_t error=0;
	if((irq_level >0) && (irq_level <16)){
		uint32_t bit = (1 << irq_level); // Mask irq level to clear
		*LEON3_ICLEAR = bit;	//Sets that bit to 1
	}else
		error=1;
	return error;
}

/** Pone a 1 el bit del irq_level correspondiente al registro IFORCE
 * forzando la interrupción del irq_level indicado.*/
/**Set the irq_level bit of IFORCE to force the interruption of this irq_level*/
uint8_t leon3_force_irq (uint8_t irq_level) {
	uint8_t error=0;
	if((irq_level >0) && (irq_level <16)){
	//OK
		// COMPLETAR Poniendo a 1 SOLO el bit correspondiente al irq_level de LEON3_IFORCE
		// COMPLETE Setting ONLY the bit corresponding to the irq_level of LEON3_IFORCE

		//Mejora:
		//No hace falta el |= 1 << irq_level;
		//puedes hacer = 1 << irq_level;
		//ya que es un registro que no almacena nunca el valor que le asignas.
		//Sólo fuerza el disparo.
		
		uint32_t bit = (1 << irq_level); // La mascara del bit a modificar
		*LEON3_IFORCE =  bit;	//Sets that bit to 1
	}else
		error=1;
	return error;
}


/** Pone a 1 el bit del irq_level indicado en el registro de mascara,
 * desenmascarando dicha interrupcion. irq_level(1-15).*/
/**Set the irq_level bit of IMASk to mask the interruption of this irq_level*/
uint8_t leon3_unmask_irq (uint8_t irq_level){
	uint8_t error=0;
	if((irq_level >0) && (irq_level <16)){
		// COMPLETAR Poniendo a 1 SOLO el bit correspondiente al irq_level de LEON3_IMASK
		// COMPLETE Setting ONLY the bit corresponding to the irq_level of LEON3_IMASK


		uint32_t bit = (1 << irq_level); // La mascara del bit a modificar
			// clear any pending irq of that level
		leon3_clear_irq(irq_level);

		//OK. Es necesario leer IMASK para guardar el valor que tenía el registro para el resto de niveles.

		//Error: No guardas el valor que tiene *LEON3_IMASK para el resto de bits
		//Modificas todos los bits
		
		*LEON3_IMASK |=  bit;	// Sets that bit to 1
	}else
		error=1;
	return error;
}


/** Pone a 0 el bit del irq_level indicado en el registro de mascara,
 * enmascarando dicha interrupción. irq_level(1-15)*/
/**Reset the irq_level bit of IMASk to mask the interruption of this irq_level*/
uint8_t leon3_mask_irq (uint8_t irq_level) {
	uint8_t error=0;
	if(irq_level >0 && irq_level <16){

		// COMPLETAR Poniendo a 0 SOLO el bit correspondiente al irq_level de LEON3_IMASK
		// COMPLETE Clearing ONLY the bit corresponding to the irq_level of LEON3_IMASK

		uint32_t bit = (1 << irq_level); // La mascara del bit a modificar

		//OK. Es necesario leer IMASK para guardar el valor que tenía el registro para el resto de niveles.

		//Error. No guardas el valor que tiene *LEON3_IMASK para el resto de bits
		//Modificas todos los bits poniendolos a 0

		*LEON3_IMASK &= ~bit;	//Sets that bit to 0
	}else
		error=1;
	return error;
}

/** Pone a 1 todos los bits del registro de mascara, desenmascarando todas las interrupciones externas*/
/** Set all the bits of IMASk to unmask all the interruptions*/
void leon3_unmask_all_irqs(){

	*LEON3_IMASK=0xFFFE;
}

/** Pone a 0 todos los bits del registro de mascara, enmascarando todas las interrupciones externas*/
/** Reset all the bits of IMASk to mask all the interruptions*/
void leon3_mask_all_irqs(){

	*LEON3_IMASK=0;
}



