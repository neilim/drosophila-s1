/*
 * system.h
 *
 *  Created on: 2023. dec. 12.
 *      Author: attil
 */

#ifndef SYSTEM_H_
#define SYSTEM_H_

#define LED_DIR P1DIR
#define LED_OUT P1OUT
#define LED_GREEN BIT6
#define LED_RED BIT0
#define LED_RED_SET() LED_OUT |= LED_RED
#define LED_RED_RESET() LED_OUT &= ~LED_RED
#define LED_RED_TOGGLE() LED_OUT ^= LED_RED
#define LED_GREEN_SET() LED_OUT |= LED_GREEN
#define LED_GREEN_RESET() LED_OUT &= ~LED_GREEN
#define LED_GREEN_TOGGLE() LED_OUT ^= LED_GREEN
#define LED_ALL_SET() LED_OUT |= LED_GREEN | LED_RED
#define LED_ALL_RESET() LED_OUT &= ~(LED_GREEN | LED_RED)
#define LED_ALL_TOGGLE() LED_OUT ^= LED_GREEN | LED_RED

typedef enum{
    system_clock_1MHZ,
    system_clock_8MHZ,
    system_clock_12MHZ,
    system_clock_16MHZ
}system_clock_t;

typedef struct{
    system_clock_t clock;
}system_status_t;
system_status_t system_status;

void system_gpio_init(void);

void system_wdt_init(void);

void system_clock_init(system_clock_t clock);

void system_startup(void);

#endif /* SYSTEM_H_ */
