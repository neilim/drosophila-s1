/*
 * uart.h
 *
 *  Created on: 2023. dec. 13.
 *      Author: attil
 */

#ifndef UART_H_
#define UART_H_


#define MCLK_HZ  16000000
#define BPS 9600
#define BAUD_RATE_20_BIT (MCLK_HZ + (BPS >> 1)) / BPS

void uart_init(void);



#endif /* UART_H_ */
