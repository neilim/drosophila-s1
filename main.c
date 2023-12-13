#include <msp430.h>
#include <system.h>
#include <uart.h>
/**
 * @brief   Drosophila Sensor type 1
 *          Remote temperature and humidity sensor with RS485 and
 *          low power modes.
 */
void main(void){
    system_startup();
    uart_init();

    TACCR0 = 32767;
    TACCTL0 |= CCIE;
    TACTL = TASSEL_1 | ID_0 |   MC_1;

    __enable_interrupt();

    while(!(IFG2 & UCA0TXIFG));                  // wait for TX buffer to be empty
    UCA0TXBUF = 'b';
    __low_power_mode_3();

    while (1){
        LED_GREEN_TOGGLE();
    }
}

#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer_A (void){
    LED_RED_TOGGLE();
    LED_GREEN_RESET();
}
