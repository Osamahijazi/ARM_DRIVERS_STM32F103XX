/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:20/8/2020***********************************/
/***********version:1***************************************/
/***********************************************************/
#include "STD_TYPES.h"
#include "MATH_BIT.h"
#include "NVIC_Interface.h"
#include "NVIC_Config.h"
#include "NVIC_Private.h"


void NVIC_voidEnableInterrupt(uint8 Copy_uint8IntNumber){

  if (Copy_uint8IntNumber <= 31){

       NVIC_ISER0 = (1 <<Copy_uint8IntNumber);

                       }

 else if (Copy_uint8IntNumber <= 59){

	    Copy_uint8IntNumber = Copy_uint8IntNumber - 32 ;
	 
      NVIC_ISER1 = (1 <<Copy_uint8IntNumber );
                   }

 else 
            {
         
					/*  Return Error*/

            }

 }

 
 void NVIC_voidDisableInterrupt(uint8 Copy_uint8IntNumber){

  if (Copy_uint8IntNumber <= 31){

       NVIC_ICER0 = (1 <<Copy_uint8IntNumber);

                       }

 else if (Copy_uint8IntNumber <= 59){

	    Copy_uint8IntNumber = Copy_uint8IntNumber - 32 ;
	 
      NVIC_ICER1 = (1 <<Copy_uint8IntNumber );
                   }

 else 
            {
         
					/*  Return Error*/

            }

 }
 
 
 
 void NVIC_voidSetPendingFlag(uint8 Copy_uint8IntNumber){

  if (Copy_uint8IntNumber <= 31){

       NVIC_ISPR0 = (1 <<Copy_uint8IntNumber);

                       }

 else if (Copy_uint8IntNumber <= 59){

	    Copy_uint8IntNumber = Copy_uint8IntNumber - 32 ;
	 
      NVIC_ISPR1 = (1 <<Copy_uint8IntNumber );
                   }

 else 
            {
         
					/*  Return Error*/

            }

 }
 
 
 
 void NVIC_voidClearPendingFlag(uint8 Copy_uint8IntNumber){

  if (Copy_uint8IntNumber <= 31){

       NVIC_ICPR0 = (1 <<Copy_uint8IntNumber);

                       }

 else if (Copy_uint8IntNumber <= 59){

	    Copy_uint8IntNumber = Copy_uint8IntNumber - 32 ;
	 
      NVIC_ICPR1 = (1 <<Copy_uint8IntNumber );
                   }

 else 
            {
         
					/*  Return Error*/

            }

 }
 
 
 
 uint8 NVIC_voidGetActiveFlag(uint8 Copy_uint8IntNumber){

	 uint8 Local_uint8LocalResult ;
	 
  if (Copy_uint8IntNumber <= 31){

		       Local_uint8LocalResult =  GET_BIT(NVIC_IABR0,Copy_uint8IntNumber);
		
                       }

 else if (Copy_uint8IntNumber <= 59){

	    Copy_uint8IntNumber = Copy_uint8IntNumber - 32 ;
	 
		      Local_uint8LocalResult =   GET_BIT(NVIC_IABR1,Copy_uint8IntNumber);
                   }

 else 
            {
         
					/*  Return Error*/

            }
						
						return Local_uint8LocalResult;

 }

                                /*TO GET THE FORTH BITS OF PRIORITY*/
 
 void NVIC_voidSetPriority( uint8 Copy_uint8IntID , uint8 Copy_uint8GroupPriority , uint8 Copy_uint8SubGroupPriority, uint32 Copy_uint32Group){
 
    uint8 Local_uint8Priority =  ( Copy_uint8SubGroupPriority | Copy_uint8GroupPriority << (( Copy_uint32Group - 0X05FFA0300) / 256 ));
   
 
       if( Copy_uint8IntID >= 0 ){
 
              NVIC_IPR[Copy_uint8IntID]= Local_uint8Priority << 4 ;
 
                }
 
       SCB_AIRCR = Copy_uint32Group;
 
 
   } 
 
 
 
 
 
 
 