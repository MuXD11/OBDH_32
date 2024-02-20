/*
 * leon3_uart.c
 *
 *  Created on: Feb 2, 2021
 *      Author: user
 */
 
#include "public/leon3_uart_drv_v1.h"

//Estructura de datos que permite acceder a los registros de la //UART de LEON3

struct UART_regs
{
	/** \brief UART  Data Register */
	volatile uint32_t Data;   	/* 0x80000100 */
	/** \brief UART  Status Register */
	volatile uint32_t Status; 	/* 0x80000104 */
	/** \brief UART  Control Register */
	volatile uint32_t Ctrl; 	/* 0x80000108 */
	/** \brief UART  Scaler Register */
	volatile uint32_t Scaler; 	/* 0x8000010C */
};

//********************************************************
//STATUS REGISTER MASKS

//!LEON3 UART A TX FIFO is full
#define LEON3_UART_TFF (0x200)

//!LEON3 UART A TX FIFO is empty
#define LEON3_UART_TFE  (0x004)


//********************************************************
//CTRL REGISTER MASKS

//!LEON3 UART CTRL RX ENABLE MASK
#define LEON3_UART_CTRL_RX_ENABLE (0x001)

//!LEON3 UART CTRL RX IRQ ENABLE MASK
#define LEON3_UART_CTRL_RX_IRQ_ENABLE (0x004)

//!LEON3 UART SET_LOOP_BACK MASK
#define LEON3_UART_CTRL_SET_LOOP_BACK  (0x080)




//Mejora: El casting (struct   UART_regs *) te permite eliminar el warning
struct  UART_regs * const pLEON3_UART_REGS= (struct   UART_regs *)0x80000100;



//**********************************************************************************
//#define leon3_UART_TF_IS_FULL()

//Mejora:
//No es necesario ((LEON3_UART_TFF & pLEON3_UART_REGS->Status)!=0)
//lo más sencillo es (LEON3_UART_TFF & pLEON3_UART_REGS->Status)
//Basta con que sea !=0


//Mejora:
//No es necesario ((LEON3_UART_TFF & pLEON3_UART_REGS->Status)==LEON3_UART_TFF)
//lo más sencillo es (LEON3_UART_TFF & pLEON3_UART_REGS->Status)
//Basta con que sea !=0

//ERROR en (LEON3_UART_TFF ==pLEON3_UART_REGS->Status)
//tienes que ver si el bit de la máscara LEON3_UART_TFF está a 1, pero otros bits
//también pueden estar a 1, con este operador igual no admites esa posibilidad

//OK
#define leon3_UART_TF_IS_FULL() (LEON3_UART_TFF&pLEON3_UART_REGS->Status)


int8_t leon3_putchar(char c)
{

	uint32_t write_timeout=0;

	while(
			(leon3_UART_TF_IS_FULL())
			&&(write_timeout < 0xAAAAA)
		){
			write_timeout++;

	}
	if(write_timeout <  0xAAAAA)
		pLEON3_UART_REGS->Data=c;

	return (write_timeout ==  0xAAAAA);
}


//**********************************************************************************
//int8_t leon3_uart_tx_fifo_is_empty()

//Mejora:Está bien, pero no es necesario hacer ((LEON3_UART_TFE & pLEON3_UART_REGS->Status)!=0)
//lo más sencillo es
//return (LEON3_UART_TFE & pLEON3_UART_REGS->Status);
//Basta con que sea !=0

//Mejora:Está bien, pero no es necesario hacer ((LEON3_UART_TFE & pLEON3_UART_REGS->Status)==LEON3_UART_TFE)
//lo más sencillo es
//return (LEON3_UART_TFE & pLEON3_UART_REGS->Status);
//Basta con que sea !=0

//ERROR: tienes que ver si el bit de la máscara LEON3_UART_TFE está a 1, pero otros bits
//también pueden estar a 1, con este operador igual no admites esa posibilidad

//OK
int8_t leon3_uart_tx_fifo_is_empty(){
	return (LEON3_UART_TFE&pLEON3_UART_REGS->Status);

}

//**********************************************************
//leon3_getchar

//OK
int8_t leon3_getchar(){

	char uart_rx_data;

	//COMPLETAR.
	uart_rx_data=pLEON3_UART_REGS->Data;

 	return uart_rx_data;
}

//**********************************************************
//leon3_uart_ctrl_rx_enable

void leon3_uart_ctrl_rx_enable()
{
	//Mejora:pLEON3_UART_REGS->Ctrl |= 0x001
	//Mejora: es mejor usar una macro como máscara

	//OK
	pLEON3_UART_REGS->Ctrl |= LEON3_UART_CTRL_RX_ENABLE;
}

//**********************************************************
//leon3_UART_ctrl_rx_irq_enable

void leon3_uart_ctrl_rx_irq_enable()
{
	//Mejora:pLEON3_UART_REGS->Ctrl |= 0x004
	//Mejora: es mejor usar una macro como máscara

	//OK
	pLEON3_UART_REGS->Ctrl |= LEON3_UART_CTRL_RX_IRQ_ENABLE;
}


//**********************************************************
//leon3_uart_ctrl_config_rxtx_loop

void leon3_uart_ctrl_config_rxtx_loop(uint8_t set_rxtxloop)
{

	//Mejora: if(set_rxtxloop==1)
	//usar if(set_rxtxloop), es lo más sencillo

	if(set_rxtxloop){

		//Mejora: pLEON3_UART_REGS->Ctrl |= 0x080
		//Mejora: es mejor usar una macro como máscara
		
		//OK
		pLEON3_UART_REGS->Ctrl |= LEON3_UART_CTRL_SET_LOOP_BACK;

	}else{

		//Mejora: pLEON3_UART_REGS->Ctrl &= ~0x080
		//Mejora: es mejor usar una macro como máscara

		//OK
		pLEON3_UART_REGS->Ctrl &= ~LEON3_UART_CTRL_SET_LOOP_BACK;
	}
}
