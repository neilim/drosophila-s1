/*
 * system.c
 *
 *  Created on: 2023. dec. 12.
 *      Author: attil
 */
#include <msp430.h>
#include <system.h>

void system_gpio_init(void){
    LED_DIR |= LED_RED | LED_GREEN;
    LED_ALL_RESET();
}

void system_wdt_init(void){
    WDTCTL = WDTPW | WDTHOLD;
}

void system_clock_init(system_clock_t clock){
    switch(clock){
        case system_clock_1MHZ:{
            DCOCTL = CALDCO_1MHZ;
            BCSCTL1 = CALBC1_1MHZ;
            BCSCTL2 = 0;
            system_status.clock=system_clock_1MHZ;
            break;
        }
        case system_clock_8MHZ:{
            DCOCTL = CALDCO_8MHZ;
            BCSCTL1 = CALBC1_8MHZ;
            BCSCTL2 = 0;
            system_status.clock=system_clock_8MHZ;
            break;
        }
        case system_clock_12MHZ:{
            DCOCTL = CALDCO_12MHZ;
            BCSCTL1 = CALBC1_12MHZ;
            BCSCTL2 = 0;
            system_status.clock=system_clock_12MHZ;
            break;
        }
        case system_clock_16MHZ:{
            DCOCTL = CALDCO_16MHZ;
            BCSCTL1 = CALBC1_16MHZ;
            BCSCTL2 = 0;
            system_status.clock=system_clock_16MHZ;
            break;
        }
        default:{
            DCOCTL = CALDCO_16MHZ;
            BCSCTL1 = CALBC1_16MHZ;
            BCSCTL2 = 0;
            system_status.clock=system_clock_16MHZ;
            break;
        }
    }
    BCSCTL3 |= XT2S_0 | LFXT1S_0 | XCAP_3;  //ACLK 32.768kHz
}

void system_startup(void){
    system_wdt_init();
    system_gpio_init();
    system_clock_init(system_clock_16MHZ);
}


