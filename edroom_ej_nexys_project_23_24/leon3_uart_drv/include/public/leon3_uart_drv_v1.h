#ifndef LEON3_UART_H_
#define LEON3_UART_H_

#include "public/basic_types.h"

#ifdef __cplusplus

extern "C" {

#endif

/** \brief put a char in the UART FIFO buffer for sending it.
 *
 *	\param c char to send
 *
 *	\return 0 if there is no error, 1 if char cannot be inserted in the FIFO buffer
 */
int8_t leon3_putchar(char c);

/** \brief get a char from the UART RX FIFO buffer.
 *
 *	\return the received char
 */

int8_t leon3_getchar();

/** \brief check if UART Tx FIFO is empty
 *
 *	\param c char to send
 *
 *	\return true if UART Tx FIFO is empty
 */
int8_t leon3_uart_tx_fifo_is_empty();

/** \brief Enable UART Rx
 */
void leon3_uart_ctrl_rx_enable();

/** \brief Enable UART Rx IRQ
 */
void leon3_uart_ctrl_rx_irq_enable();

/** \brief config UART RxTx Loop
 *
 *	\param set_rxtxloop if(set_rxtxloop) RxTx Loop will enabled else will be disabled
 */
void leon3_uart_ctrl_config_rxtx_loop(uint8_t set_rxtxloop);

#ifdef __cplusplus

}
#endif

#endif /* LEON3_UART_H_ */
