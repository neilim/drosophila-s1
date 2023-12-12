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
            system_status.clock=system_clock_1MHZ;
            break;
        }
        case system_clock_8MHZ:{
            system_status.clock=system_clock_8MHZ;
            break;
        }
        case system_clock_12MHZ:{
            system_status.clock=system_clock_12MHZ;
            break;
        }
        case system_clock_16MHZ:{
            system_status.clock=system_clock_16MHZ;
            break;
        }
    }
}

void system_startup(void){
    system_wdt_init();
    system_gpio_init();
}


