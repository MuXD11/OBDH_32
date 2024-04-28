/*
 * leon3_irqs.h
 *
 *  Created on: Feb 28, 2013
 *      Author: user
 */

#ifndef IRQS_H_
#define IRQS_H_

#include "public/basic_types.h"

#ifdef __cplusplus

extern "C" {

#endif

//Rutina que enmascara la interrupción externa cuyo nivel se pasa por parámetro.
//Mask the external interrupt of irq_level
uint8_t leon3_mask_irq (uint8_t irq_level);

//Rutina que desenmascara una interrupción externa cuyo nivel se pasa por parámetro.
//Unmask the external interrupt of irq_level
uint8_t leon3_unmask_irq (uint8_t irq_level);

//Rutina que enmascara todas las interrupciones externas
//Mask all the external interrupts
void leon3_mask_all_irqs();

//Rutina que enmascara todas las interrupciones externas
//Unmask all the external interrupts
void leon3_unmask_all_irqs();


//Rutina que fuerza una interrupción externa cuyo nivel se pasa por parámetro.
//Force the external interrupt of irq_level
uint8_t leon3_force_irq (uint8_t irq_level);

//Rutina que borra una interrupción externa pendiente cuyo nivel se pasa por parámetro.
//clear the pending external interrupt of irq_level
uint8_t leon3_clear_irq (uint8_t irq_level);

#ifdef __cplusplus

}

#endif

#endif
