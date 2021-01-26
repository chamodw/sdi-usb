/*
 * Sensor.c
 *
 * Created: 16/05/2020 4:07:44 PM
 * Author : csam754
 */ 

#include "sam.h"
#include "device.h"
#include "sercom_i2c.h"
#include <string.h>

#include "device.h"
#include "USB/usb_lib.h"
#include "USB/usbserial.h"
#include "clock.h"

int main(void)
{
	SystemInit();
	
	clock_init();
	dev_init(); //Initialize device
	/* TODO: Check this pin config
	*/
	PORT->Group[0].DIRSET.reg = (3 << 22);
	PORT->Group[0].PINCFG[22].bit.INEN = 1;
	i2c_init();
	
#define NO_USB1

#ifndef NO_USB
	usb_init();
	usb_attach();
#endif
	//Wait for enumeration to complete
	clock_delayMs(100);
	
#ifndef NO_USB
	usbserial_init();
#endif
	
	
	
	//Wait for enumeration to complete
	clock_delayMs(100);
	



	uint32_t timestamp = clock_getTicks();
	
	while (1)
	{
	

	

		
		
		
	}
	

}


void HardFault_Handler(){
	
	for(;;);
	};
	
