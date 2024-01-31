#ifndef LEON3_BPRINT_H_
#define LEON3_BPRINT_H_

/** \brief send a string in the UART FIFO buffer for sending it.
 *
 *	\param str pointer to the string
 *
 *	\return 0 if there is no error, 1 if the string cannot be sent
 */

  int8_t leon3_print_string(char* str);

/** \brief send the characters of the uint8_t to the UART
 *
 *	\param i uint8_t to send
 *
 *	\return 0 if there is no error, 1 if the uint8_t cannot be sent
 */

  int8_t leon3_print_uint8(uint8_t i);


  /** \brief send the characters of the uint32_t to the UART
   *
   *	\param i uint32_t to send
   *
   *	\return 0 if there is no error, 1 if the uint32_t cannot be sent
   */

    int8_t leon3_print_uint32(uint32_t i);

#endif /*LEON3_BPRINT_H_*/
