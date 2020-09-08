/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:20/8/2020***********************************/
/***********version:1***************************************/
/***********************************************************/

#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

#include "STD_TYPES.h"

                                     /*MACROS*/
																		 
																		 
																		 /*EXTERNAL INTERRUPT  SOFTWARE NUMBER*/

#define         EXTI0                   6
#define         EXTI1                   7
#define         EXTI2                   8
#define         EXTI3                   9
#define         EXTI4                   10S

                               /*FUNCTIONS PROTOTYPE*/

 void  NVIC_voidEnableInterrupt (uint8 Copy_uint8IntNumber);
 void  NVIC_voidDisableInterrupt(uint8 Copy_uint8IntNumber);
 void  NVIC_voidSetPendingFlag  (uint8 Copy_uint8IntNumber);
 void  NVIC_voidClearPendingFlag(uint8 Copy_uint8IntNumber);
 uint8 NVIC_voidGetActiveFlag   (uint8 Copy_uint8IntNumber);
 void  NVIC_voidSetPriority     ( uint8 Copy_uint8IntID , uint8 Copy_uint8GroupPriority , uint8 Copy_uint8SubGroupPriority, uint32 Copy_uint32Group);







#endif