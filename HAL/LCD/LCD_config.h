/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:13/9/2020***********************************/
/***********version:1***************************************/
/*********Description:LCD DRIVER***********************/
/***********************************************************/


#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H

#include "STD_TYPES.h"

/***********************************************************************************************************************************************************************************************************************************************************/

                                                      /*Registers Macros*/
#define  GPIOA      0
#define  GPIOB      1
#define  GPIOC      2

                                                         /*Pins Macros*/
#define PIN0        0
#define PIN1        1
#define PIN2        2
#define PIN3        3
#define PIN4        4
#define PIN5        5
#define PIN6        6
#define PIN7        7
#define PIN8        8
#define PIN9        9
#define PIN10       10
#define PIN011      11
#define PIN012      12
#define PIN13       13 
#define PIN14       14
#define PIN15       15

/***********************************************************************************************************************************************************************************************************************************************************/
                                       /*                      Preprocessor Macros                                    */
/***********************************************************************************************************************************************************************************************************************************************************//* LCD Data bits mode configuration */

#define DATA_BITS_MODE   8                           /*CHOOSE DATA BITS MMODE*/


/***********************************************************************************************************************************************************************************************************************************************************/
                                                              /* LCD HARDWARE Pins */

                                                                      /*CHOOSE CONTROL PORT*/
#define LCD_CONTROL_PORT_RS          GPIOB
#define LCD_CONTROL_PORT_RW          GPIOB
#define LCD_CONTROL_PORT_EN          GPIOB

uint8 LCD_CONTROL_PORT[3]={LCD_CONTROL_PORT_RS,LCD_CONTROL_PORT_RW,LCD_CONTROL_PORT_EN};

                                                                      /*CHOOSE CONTROL PIN*/
#define LCD_CONTROL_PIN_RS           PIN0
#define LCD_CONTROL_PIN_RW           PIN1
#define LCD_CONTROL_PIN_EN           PIN2

uint8 LCD_CONTROL_PIN[3]={LCD_CONTROL_PIN_RS,LCD_CONTROL_PIN_RW,LCD_CONTROL_PIN_EN};
                                                                    /*CONTROL PINS REPRESENTATION*/
#define      RS           LCD_CONTROL_PIN_RS
#define      RW           LCD_CONTROL_PIN_RW
#define      EN           LCD_CONTROL_PIN_EN

                                                                      /*CHOOSE DATA PORT*/
#define LCD_DATA_PORT_D0              GPIOA
#define LCD_DATA_PORT_D2              GPIOA
#define LCD_DATA_PORT_D1              GPIOA
#define LCD_DATA_PORT_D3              GPIOA
#define LCD_DATA_PORT_D4              GPIOA
#define LCD_DATA_PORT_D5              GPIOA
#define LCD_DATA_PORT_D6              GPIOA
#define LCD_DATA_PORT_D7              GPIOA

uint8 LCD_DATA_PORT[8]={LCD_DATA_PORT_D0,LCD_DATA_PORT_D1,LCD_DATA_PORT_D2,LCD_DATA_PORT_D3,LCD_DATA_PORT_D4,LCD_DATA_PORT_D5,LCD_DATA_PORT_D6,LCD_DATA_PORT_D7};

                                                                       /*CHOOSE DATA PIN*/
#define LCD_DATA_PIN_D0               PIN0
#define LCD_DATA_PIN_D1               PIN1
#define LCD_DATA_PIN_D2               PIN2
#define LCD_DATA_PIN_D3               PIN3
#define LCD_DATA_PIN_D4               PIN4
#define LCD_DATA_PIN_D5               PIN5
#define LCD_DATA_PIN_D6               PIN6
#define LCD_DATA_PIN_D7               PIN7

uint8 LCD_DATA_PIN[8]={LCD_DATA_PIN_D0,LCD_DATA_PIN_D1,LCD_DATA_PIN_D2,LCD_DATA_PIN_D3,LCD_DATA_PIN_D4,LCD_DATA_PIN_D5,LCD_DATA_PIN_D6,LCD_DATA_PIN_D7};

                                                                      /* LCD Commands */
#define CLEAR_COMMAND                 0x01
#define FOUR_BITS_DATA_MODE           0x02
#define TWO_LINE_LCD_Four_BIT_MODE    0x28
#define TWO_LINE_LCD_Eight_BIT_MODE   0x38
#define CURSOR_OFF                    0x0C
#define CURSOR_ON                     0x0E
#define SET_CURSOR_LOCATION           0x80 

/***********************************************************************************************************************************************************************************************************************************************************/
                                 
#endif 

