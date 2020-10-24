/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:13/9/2020***********************************/
/***********version:1***************************************/
/*********Description:LCD DRIVER***********************/
/***********************************************************/
#include "STD_TYPES.h"
#include "MATH_BIT.h"
#include "GPIO_interface.h"
#include "SYSTIMER_Interface.h"
#include "LCD_config.h"
#include "LCD_Private.h"
#include "LCD_Interface.h"

void LCD_init(void)                                       /*LCD Init configuration*/
{
	                                        
	for(uint8 i = 0 ; i<3 ; i ++ ){   /* Configure the control pins(E,RS,RW) as output pins */
	
	GPIO_VoidSetPinDirection(LCD_CONTROL_PORT[i],LCD_CONTROL_PIN[i],GPIO_HIGH);
	}
	
#if (DATA_BITS_MODE == 4)
	
        for(uint8 i = 0 ; i<4 ; i ++ ){   /* Configure the lowest 4 bits of the data port as output pins */
	      GPIO_VoidSetPinValue(LCD_DATA_PORT[i],LCD_DATA_PIN[i],GPIO_HIGH);
	                       }		
		LCD_sendCommand(FOUR_BITS_DATA_MODE); /* initialize LCD in 4-bit mode */
		LCD_sendCommand(TWO_LINE_LCD_Four_BIT_MODE); /* use 2-line lcd + 4-bit Data Mode + 5*7 dot display Mode */
	
#endif		 

#if (DATA_BITS_MODE == 8)
        for(uint8 i = 0 ; i<8 ; i ++ ){    /* Configure the data port as output port */
	      GPIO_VoidSetPinDirection(LCD_DATA_PORT[i],LCD_DATA_PIN[i],GPIO_HIGH);
	                         }												
	LCD_sendCommand(TWO_LINE_LCD_Eight_BIT_MODE); /* use 2-line lcd + 8-bit Data Mode + 5*7 dot display Mode */
#endif
	LCD_sendCommand(CURSOR_OFF); /* cursor off */
	LCD_sendCommand(CLEAR_COMMAND); /* clear LCD at the beginning */
}

void LCD_sendCommand(uint8 command)
{
	GPIO_VoidSetPinValue(LCD_CONTROL_PORT[0],LCD_CONTROL_PIN[0],GPIO_LOW);/* Instruction Mode RS=0 */
	
  GPIO_VoidSetPinValue(LCD_CONTROL_PORT[1],LCD_CONTROL_PIN[1],GPIO_LOW); /* write data to LCD so RW=0 */
	
  STK_voidSetBusyWait(1); /* delay for processing Tas = 50ns */
	
	GPIO_VoidSetPinValue(LCD_CONTROL_PORT[2],LCD_CONTROL_PIN[2],GPIO_HIGH);/* Enable LCD E=1 */

	STK_voidSetBusyWait(1); /* delay for processing Tpw - Tdws = 190ns */
	
#if  DATA_BITS_MODE == 4
	                                      
	                             /* out the highest 4 bits of the required command to the data bus D0 --> D3 */
	
       for(uint8 i = 0 ; i<4 ; i ++ ){   /*CLEAR LOWEST FOUR BITS*/
       GPIO_VoidSetPinValue(LCD_DATA_PORT[i],LCD_DATA_PIN[i],GPIO_LOW);
			                 	}		
	     for(uint8 i = 0; i<4 ; i ++ ){   /*VALUE = (command & 0xF0) >>4*/
       GPIO_VoidSetPinValue(LCD_DATA_PORT[i],LCD_DATA_PIN[i],(GET_BIT(command,i) & (GET_BIT(0XF0,i)>>4)));
			                 	}

 STK_voidSetBusyWait(1); /* delay for processing Tdsw = 100ns */
												
	GPIO_VoidSetPinValue(LCD_CONTROL_PORT[2],LCD_CONTROL_PIN[2],GPIO_LOW); /* disable LCD E=0 */
												
	STK_voidSetBusyWait(1); /* delay for processing Th = 13ns */
												
	GPIO_VoidSetPinValue(LCD_CONTROL_PORT[2],LCD_CONTROL_PIN[2],GPIO_HIGH); /* Enable LCD E=1 */
												
	STK_voidSetBusyWait(1); /* delay for processing Tpw - Tdws = 190ns */
											
	                           /* out the lowest 4 bits of the required command to the data bus D0 --> D3 */
												
      for(uint8 i = 0 ; i<4 ; i ++ ){   /*CLEAR LOWEST FOUR BITS*/
      GPIO_VoidSetPinValue(LCD_DATA_PORT[i],LCD_DATA_PIN[i],GPIO_LOW);
			                 	}		
	    for(uint8 i = 0; i<4 ; i ++ ){   /*VALUE = (command & 0xF0) >>4*/
      GPIO_VoidSetPinValue(LCD_DATA_PORT[i],LCD_DATA_PIN[i],(GET_BIT(command,i) & (GET_BIT(0X0F,i))));
			                 	}   
	STK_voidSetBusyWait(1); /* delay for processing Tdsw = 100ns */
												
	GPIO_VoidSetPinValue(LCD_CONTROL_PORT[2],LCD_CONTROL_PIN[2],GPIO_LOW); /* disable LCD E=0 */
												
 	STK_voidSetBusyWait(1); /* delay for processing Tdsw = 100ns */
	
	#endif

												
#if (DATA_BITS_MODE == 8)
						
      for(uint8 i = 0; i<8 ; i ++ ){              /*OUTPUT DATA = (command )*/
      GPIO_VoidSetPinValue(LCD_DATA_PORT[i],LCD_DATA_PIN[i],GET_BIT(command,i));
			                 	}												
												
	STK_voidSetBusyWait(1); /* delay for processing Tdsw = 100ns */
												
	GPIO_VoidSetPinValue(LCD_CONTROL_PORT[2],LCD_CONTROL_PIN[2],GPIO_LOW); /* disable LCD E=0 */
												
	STK_voidSetBusyWait(1); /* delay for processing Th = 13ns */
												
#endif

}

void LCD_displayCharacter(uint8 DATA)
{
	GPIO_VoidSetPinValue(LCD_CONTROL_PORT[0],LCD_CONTROL_PIN[0],GPIO_HIGH); /* Data Mode RS=1 */
	
	GPIO_VoidSetPinValue(LCD_CONTROL_PORT[1],LCD_CONTROL_PIN[1],GPIO_LOW); /* write data to LCD so RW=0 */
	
	STK_voidSetBusyWait(1); /* delay for processing Tas = 50ns */
	
	GPIO_VoidSetPinValue(LCD_CONTROL_PORT[2],LCD_CONTROL_PIN[2],GPIO_HIGH); /* Enable LCD E=1 */
	
	STK_voidSetBusyWait(1); /* delay for processing Tpw - Tdws = 190ns */
	
	    for(uint8 i = 0; i<8 ; i ++ ){   /* out the required data char to the data bus D0 --> D7 */
      GPIO_VoidSetPinValue(LCD_DATA_PORT[i],LCD_DATA_PIN[i],GET_BIT(DATA,i));
			                  	} 
	STK_voidSetBusyWait(1); /* delay for processing Tdsw = 100ns */
	
	GPIO_VoidSetPinValue(LCD_CONTROL_PORT[2],LCD_CONTROL_PIN[2],GPIO_LOW); /* disable LCD E=0 */
	
	STK_voidSetBusyWait(1); /* delay for processing Th = 13ns */	
}


void LCD_displayString(const char *Str)              /*DISPLAY STRING ON LCD*/
{
	uint8 i = 0;
	while(Str[i] != '\0')
	{
		LCD_displayCharacter(Str[i]);
		i++;
	}
	/***************** Another Method ***********************
	while((*Str) != '\0')
	{
		LCD_displayCharacter(*Str);
		Str++;
	}		
	*********************************************************/
}												

void LCD_goToRowColumn(uint8 row,uint8 col)
{
	uint8 Address ;
	
	/* first of all calculate the required address */
	switch(row)
	{
		case 0:
				Address=col;
				break;
		case 1:
				Address=col+0x40;
				break;
		case 2:
				Address=col+0x10;
				break;
		case 3:
				Address=col+0x50;
				break;
	}										
		                                         /* to write to a specific address in the LCD*/ 
	                               /*we need to apply the corresponding command 0b10000000+Address */
	
	LCD_sendCommand( Address | SET_CURSOR_LOCATION); 
}																				
		 
void LCD_displayStringRowColumn(uint8 row,uint8 col,const char *Str)
{
	LCD_goToRowColumn(row,col); /* go to to the required LCD position */
	LCD_displayString(Str); /* display the string */
}
/*      
void LCD_intgerToString(int data)
{
   char buff[16]; 
   itoa(data,buff,10); 
   LCD_displayString(buff);
}
*/
void LCD_clearScreen(void)
{
	LCD_sendCommand(CLEAR_COMMAND); 
}
					
