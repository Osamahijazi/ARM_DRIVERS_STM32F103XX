/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:23/9/2020***********************************/
/***********version:1***************************************/
/*********Description:TFT DRIVER***********************/
/***********************************************************/

#include "STD_TYPES.h"
#include "MATH_BIT.h"
#include "GPIO_interface.h"
#include "SPI_Interface.h"
#include "SYSTIMER_Interface.h"
#include "TFT_Interface.h"
#include "TFT_Private.h"
#include "TFT_Config.h"

void TFT_voidInit   (void){/*TFT Init*/
 
                          /* Reset Pulse */
	GPIO_VoidSetPinValue(TFT_RST_PIN,GPIO_HIGH);
	STK_voidSetBusyWait(100);
	GPIO_VoidSetPinValue(TFT_RST_PIN,GPIO_HIGH);
	STK_voidSetBusyWait(1);
	GPIO_VoidSetPinValue(TFT_RST_PIN,GPIO_HIGH);
	STK_voidSetBusyWait(100);
	GPIO_VoidSetPinValue(TFT_RST_PIN,GPIO_HIGH);
	STK_voidSetBusyWait(100);
	GPIO_VoidSetPinValue(TFT_RST_PIN,GPIO_HIGH);
	STK_voidSetBusyWait(120000);
	
           	/* Sleep Out Command */
	TFT_voidWriteCommand(0x11);
	
          	/* Wait 150 ms */
	STK_voidSetBusyWait(150000);
	
	        /* Color Mode Command */
	TFT_voidWriteCommand(0x3A);
	TFT_voidWriteData   (0x05);
	
	        /* Display On Command */
	TFT_voidWriteCommand(0x29);
	
}
void TFT_voidDisplayImage (const uint16* Copy_Image){/*GET IMAGES SAVED IN FLASH*/

	uint16 counter;
	uint8 Data;

	/* Set X Address */
	TFT_voidWriteCommand(0x2A);
	TFT_voidWriteData(0);
	TFT_voidWriteData(0);
	TFT_voidWriteData(0);
	TFT_voidWriteData(127);
	
	/* Set Y Address */
	TFT_voidWriteCommand(0x2B);
	TFT_voidWriteData(0);
	TFT_voidWriteData(0);
	TFT_voidWriteData(0);
	TFT_voidWriteData(159);

	                    /* RAM Write */
	TFT_voidWriteCommand(0x2C);

	for(counter = 0; counter< 20480;counter++)
	{
		Data = Copy_Image[counter] >> 8;

		/* Write the high byte */
		TFT_voidWriteData(Data);
		            /* Write the low byte */
		Data = Copy_Image[counter] & 0x00ff;
		TFT_voidWriteData(Data);
	}
	
}

void TFT_voidFillColor ( uint16 Copy_Color){/*DRAW SPECIFIC COLORS*/

	uint16 counter;
	uint8 Data;

	/* Set X Address */
	TFT_voidWriteCommand(0x2A);
	TFT_voidWriteData(0);
	TFT_voidWriteData(0);
	TFT_voidWriteData(0);
	TFT_voidWriteData(127);
	
	/* Set Y Address */
	TFT_voidWriteCommand(0x2B);
	TFT_voidWriteData(0);
	TFT_voidWriteData(0);
	TFT_voidWriteData(0);
	TFT_voidWriteData(159);

	                    /* RAM Write */
	TFT_voidWriteCommand(0x2C);

	for(counter = 0; counter< 20480;counter++)
	{
		
				           /* Write the high byte */
		Data = Copy_Color >> 8;
		TFT_voidWriteData(Data);
		            /* Write the low byte */
		Data = Copy_Color & 0x00ff;
		TFT_voidWriteData(Data);
	}
	
}

void TFT_voidDrawRecrtan (uint8 x1,uint8 x2,uint8 y1,uint8 y2, uint16 Copy_Color){/*DRAW SPECIFIC COLORS*/

	uint16 counter;
	uint8 Data;

	uint16 size = (x2-x1)*(y2-y1);
	/* Set X Address */
	TFT_voidWriteCommand(0x2A);
	TFT_voidWriteData(0);
	TFT_voidWriteData(x1); /*start piont of row*/
	TFT_voidWriteData(0);
	TFT_voidWriteData(x2);/*end piont of roww */
	
	/* Set Y Address */
	TFT_voidWriteCommand(0x2B);
	TFT_voidWriteData(0);
	TFT_voidWriteData(y1);
	TFT_voidWriteData(0);
	TFT_voidWriteData(y2);

	                    /* RAM Write */
	TFT_voidWriteCommand(0x2C);

	for(counter = 0; counter< size;counter++)
	{
		
				           /* Write the high byte */
		Data = Copy_Color >> 8;
		TFT_voidWriteData(Data);
		            /* Write the low byte */
		Data = Copy_Color & 0x00ff;
		TFT_voidWriteData(Data);
	}
	
}
 
 void TFT_voidWriteCommand(uint8 Copy_uint8command){ 

                    /*SET A0 PIN TO LOW*/
GPIO_VoidSetPinValue(TFT_A0_PIN,GPIO_LOW);
	
	              /* Send Command over SPI */
(void)SPI1_uint16SendReceiveSynch(Copy_uint8command); /*Sent command */

}

 void TFT_voidWriteData(uint8 Copy_uint8Data){ 

                /*SET A0 PIN TO HIGH*/
		GPIO_VoidSetPinValue(TFT_A0_PIN,GPIO_HIGH);
	
              /* Send data over SPI */
(void)SPI1_uint16SendReceiveSynch(Copy_uint8Data); /*Sent Data */


}

