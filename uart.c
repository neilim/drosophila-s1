/*
 * uart.c
 *
 *  Created on: 2023. dec. 13.
 *      Author: attil
 */
#include <msp430.h>
#include <uart.h>
#include <system.h>

void uart_init(void){
    P1DIR &= ~(BIT1 | BIT2);
    P1SEL |= BIT1 + BIT2;
    P1SEL2 |= BIT1 + BIT2;

    UCA0CTL1 = UCSWRST;
    UCA0CTL0 = 0;
    UCA0BR1 = (BAUD_RATE_20_BIT >> 12) & 0xFF;
    UCA0BR0 = (BAUD_RATE_20_BIT >> 4) & 0xFF;
    UCA0MCTL = ((BAUD_RATE_20_BIT << 4) & 0xF0) | UCOS16;
    UCA0CTL1 = UCSSEL_2;
    UC0IE |= UCA0RXIE;
}

#pragma vector=USCIAB0RX_VECTOR
__interrupt void USCI0RX_ISR(void){
    IFG2 &= ~UCA0RXIFG;
    if (UCA0RXBUF == 'a'){
        UC0IE |= UCA0TXIE;
        UCA0TXBUF = 'b';
    }
}

#pragma vector=USCIAB0TX_VECTOR
__interrupt void USCI0TX_ISR(void){
    IFG2 &= ~UCA0TXIFG;
    LED_GREEN_SET();
}
