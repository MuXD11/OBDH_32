/*
 * leon3_bprint.c
 *
 *  Created on: Mar 15, 2020
 *      Author: user
 */

#include "../include/leon3_uart.h"

int8_t leon3_print_string(char* str){

	int8_t error=0;

    //Mejora si usa break; 
    //El uso de breaks es 
	//mejor evitarlo. 
	//Para evitarlo puedes hacer
	//int8_t error=0;
	//while(*str!='\0'&&(!error)){
  		//error = leon3_putchar(*str);
  			
	//Mejora: while(*str!='\0'){
	//funciona, pero mejor si tratas errores
    //int8_t error=0;
    //while(str[i]!='\0'&&(!error)){
   
	while(*str!='\0'&&(!error)){
		error=leon3_putchar(*str);
		//error=leon3_putchar(str[i]);
		str++;
	}

	//Error: Debes añadir la espera a que la fifo de transmisión se vacie
	while(!leon3_uart_tx_fifo_is_empty())
	 ;

	//Debes retornar el error
	//return error;
	return error;
	
	 
}

int8_t leon3_print_uint8(uint8_t i){
	
	int8_t error=0;
	uint8_t aux;
	int8_t first_digit=1;
	aux=100;
	
	//Error uso de sprintf: 
	//No se puede usar sprintf... se trata 
	//de comprender cómo hacer una gestión propia 
	//de la salida a bajo nivel, no de usar bibliotecas. 
	
	
	//Mejora: El código no usa un bucle.
	//Aunque el código funciona bien,
	//se puede hacer de forma iterativa con un while
	//en vez de usar if else if... 
	//Sería algo así
	//int8_t error=0;
	//int8_t first_digit=0;
	//uint8_t aux=100;
	//if(i==0)
	//	leon3_putchar('0');
	//else{
		//while(aux&&(!error)){
		
		// aux=aux/10; //centenas->decenas->unidades
		//} 
		

	if(i==0)
		error=leon3_putchar('0');
	else{
		while(aux&&(!error)){
			uint8_t digit;

			digit=i/aux;
			i-=aux*digit;
			aux=aux/10;
			if((0==first_digit)||digit){
				error=leon3_putchar('0'+digit);
				first_digit=0;
			   //ojo ceros a la izquierda
			}
		}
	}

	//Error: Debes añadir la espera a que la fifo de transmisión se vacie
	while(!leon3_uart_tx_fifo_is_empty())
		;
	
	//Mejora: return error; //trata el error
	return error;
	
	//Mejora: si no trata bien los ceros a la izquierda
	//La idea del bucle es buena, pero luego no lo usas
	//Una variable de control como first_digit te puede ayudar a evitar los ceros a la izquierda
	//sin necesidad de las comparaciones (i>=100) i(>=10) etc.
	//int8_t first_digit=0; //detects first digit has been printed, so any 0 must be also printed
	//Si además usas aux=aux/10; al final del bucle, no necesitarías los if
	//int aux=100; /primero busco centenas

}


int8_t leon3_print_uint32(uint32_t i){
	
	int8_t error=0;
	uint32_t aux;
	int8_t first_digit=0;
	aux=1000000000;

	//Error uso de sprintf:
	//No se puede usar sprintf... se trata
	//de comprender cómo hacer una gestión propia 
	//de la salida a bajo nivel, no de usar bibliotecas. 


	//Mejora: El código no usa un bucle.
	//Aunque el código funciona bien,
	//se puede hacer de forma iterativa con un while
	//en vez de usar if else if...
	//Sería algo así
	//int8_t error=0;
	//int8_t first_digit=0;
	//uint32_t aux=1000000000; // aux para extraer dígitos
	//if(i==0)
	//	leon3_putchar('0');
	//else{
		//while(aux&&(!error)){
	
		// aux=aux/10; //centenas->decenas->unidades
		//}


	//Mejora:
	//No manejas el error, e imprimes los ceros a la izquierda

	if(i==0)
		leon3_putchar('0');
	else{
		while(aux&&(!error)){
			uint8_t digit;

			digit=i/aux;
			i-=aux*digit;
			aux=aux/10;
			if(first_digit||digit){
				error=leon3_putchar('0'+digit);
				first_digit=1;
			}
		}
	}
	return error;
	
}
