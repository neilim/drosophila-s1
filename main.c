#include <msp430.h>
#include <system.h>
/**
 * @brief   Drosophila Sensor type 1
 *          Remote temperature and humidity sensor with RS485 and
 *          low power modes.
 */
void main(void){
    system_startup();

    int i;
	while(1){
		LED_ALL_TOGGLE();
		for(i=10000; i>0; i--);
	}
}
