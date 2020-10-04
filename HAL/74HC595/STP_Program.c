/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:16/9/2020***********************************/
/***********version:2***************************************/
/***********************************************************/
#include "STD_TYPES.h"
#include "MATH_BIT.h"
#include "STP_Private.h"
#include "STP_Config.h"
#include "STP_Interface.h"
#include "GPIO_interface.h"
#include "SYSTIMER_Interface.h"


	                                        /*DISPLAY 1BYTE ON THE OUTPUT PORT*/
                                         /*SEND BIT BY BIT FROM  MSB TO LSB*/
void STP_voidSendSynchronous(uint8 Copy_uint8DataToSend){


 sint8  Local_uint8Counter ;
 uint8 Local_uint8Bit;
	
	for(Local_uint8Counter = 7 ; Local_uint8Counter >=0 ; Local_uint8Counter--){
	
		                             /*SEND BIT BY BIT ON THE LINE*/
		
	Local_uint8Bit = GET_BIT(Copy_uint8DataToSend,Local_uint8Counter);
	GPIO_VoidSetPinValue(STP_SERIAL_DATA,Local_uint8Bit);

		                            /*SEND PULSE TO SHIFT REG*/

 GPIO_VoidSetPinValue(STP_SHIFT_CLOCK,GPIO_HIGH);	
 STK_voidSetBusyWait(1);				
 GPIO_VoidSetPinValue(STP_SHIFT_CLOCK,GPIO_LOW);	
 STK_voidSetBusyWait(1);
	}
	
	
}

void STP_voidSendStorageClock(void){  /* Display The output on The line*/

                                /*SEND PULSE TO STORAGE REG*/
	
GPIO_VoidSetPinValue(STP_STORE_CLOCK,GPIO_HIGH);	
STK_voidSetBusyWait(1);		
GPIO_VoidSetPinValue(STP_STORE_CLOCK,GPIO_LOW);	
STK_voidSetBusyWait(1);
	
}



