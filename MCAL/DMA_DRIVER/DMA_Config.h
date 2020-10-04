/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:13/9/2020***********************************/
/***********version:1***************************************/
/*********Description:DMA DRIVER***********************/
/***********************************************************/


#ifndef DMA_CONFIG_H
#define DMA_CONFIG_H

#include "STD_TYPES.h"


/***********************************************************************************************************************************************************************************************************************************************************/
                                                    /*CCR REGISTER CONFIGURATION*/
   
                                     /*CHANNEL ID CONFIGURATION   1  TO 7 */

#define  Channel_ID             First    

                                     /*Memory Mode Configuration*/
																		 
#define  Mem_To_Mem_Mode           DISABLE

                                     /*CHANNEL PERIORITY   "very high - high - meduim - low"*/
																		 
#define Channel_Periority          very_high     
 
                                         /*CHANNEL CICULARITY */

#define Circular_Mode              DISABLE

                                      /*Memory size configuration "ONE_BYTE to TWO_BYTE"*/

#define Memory_Size                 ONE_BYTE           

                                      /*Peripheral Size Configuration "ONE_BYTE to TWO_BYTE"*/

#define Peripheral_Size              ONE_BYTE           
 
                                      /*Memory increment mode"ENABLE or DISABLE"*/

#define Memory_Increment_mode        ENABLE

                                      /*Peripheral increment mode "ENABLE or DISABLE"*/

#define Peripheral_Increment_mode     ENABLE

                                         /*DATA TRANSFER DIRECTION ENABLE from memory or peripherial*/
																				 
#define DATA_DIRECTION         READ_FROM_PERIPH

                                         /*TRANSFERCOMPLETE  INTERRUPT ENABLE*/

#define TRANSFER_INTERRUPT          DISABLE
																			 

/***********************************************************************************************************************************************************************************************************************************************************/










#endif 