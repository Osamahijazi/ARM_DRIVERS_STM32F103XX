/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:14/8/2020***********************************/
/***********version:1***************************************/
/*********Description:GPIOS REGISTERS***********************/
/***********************************************************/
#include "STD_TYPES.h"
#include "MATH_BIT.h"
#include "GPIO_private.h"
#include "GPIO_interface.h"
#include "GPIO_config.h"

	 static uint8 Seven_seg_counter ;

void GPIO_VoidSetPinDirection(uint8 Copy_u8Port,uint8 Copy_u8Pin,uint8 Copy_u8Mode){

switch (Copy_u8Port)
{
  
  	case GPIOA :
		
                    if (Copy_u8Pin <= 7 ){
								
								   	GPIOA_CRL &= ~((VoidSetPinDirection_Bits_Masking) << (Copy_u8Pin * Bits_Shifting_number));
								  	GPIOA_CRL |=  ((Copy_u8Mode)<< (Copy_u8Pin * Bits_Shifting_number ));
								} 
										
              else   
                    if (Copy_u8Pin <= Max_Reg_Bits){
											
											Copy_u8Pin = Copy_u8Pin -8 ;
											GPIOA_CRH &= ~((VoidSetPinDirection_Bits_Masking)<< (Copy_u8Pin * Bits_Shifting_number));
									    GPIOA_CRH |=  ((Copy_u8Mode)<< (Copy_u8Pin * Bits_Shifting_number ));			
	 							}
	                 break;
													
								
   case GPIOB : 
		
	                  if (Copy_u8Pin <= 7 ){
								
								   	GPIOB_CRL &= ~((VoidSetPinDirection_Bits_Masking)<< (Copy_u8Pin * 4));
								  	GPIOB_CRL |= ((Copy_u8Mode)<< (Copy_u8Pin * Bits_Shifting_number ));
								} 
										
              else   
                    if (Copy_u8Pin <= 15){
											Copy_u8Pin = Copy_u8Pin -8 ;
											GPIOB_CRH &= ~((VoidSetPinDirection_Bits_Masking)<< (Copy_u8Pin * Bits_Shifting_number));
									    GPIOB_CRH |= ((Copy_u8Mode)<< (Copy_u8Pin * Bits_Shifting_number ));			
	 							}
	
								     break;
	
   case GPIOC :                 /*NOTE: PORTC HAS ONLY 3 PINS*/
		  
	                 if (Copy_u8Pin <= 7 ){
								
								   	GPIOC_CRL &= ~(( VoidSetPinDirection_Bits_Masking)<< (Copy_u8Pin * Bits_Shifting_number));
								  	GPIOC_CRL |= ((Copy_u8Mode)<< (Copy_u8Pin * Bits_Shifting_number ));
								} 
										
              else   
                    if (Copy_u8Pin <= 15){
											Copy_u8Pin = Copy_u8Pin - 8 ;
											GPIOC_CRH &= ~((VoidSetPinDirection_Bits_Masking)<< (Copy_u8Pin * Bits_Shifting_number));
									    GPIOC_CRH |= ((Copy_u8Mode)<< (Copy_u8Pin * Bits_Shifting_number ));			
	 							}
	
                      break;

}

}


                                /*FUNCTION TO SET THE PIN VALUE*/

void GPIO_VoidSetPinValue(uint8 Copy_u8Port,uint8 Copy_u8Pin,uint8 Copy_u8Value){

                     
               switch (Copy_u8Port)
{
  
  	case GPIOA :
		
                    if (Copy_u8Value == GPIO_HIGH ){
											
											SET_BIT(GPIOA_ODR,Copy_u8Pin);
											
								} 
										
              else   
                    if (Copy_u8Value == GPIO_LOW){
											
										  CLEAR_BIT(GPIOA_ODR,Copy_u8Pin);			
	 							}
	                 break;


    case GPIOB :
		
                    if (Copy_u8Value == GPIO_HIGH ){
											
											SET_BIT(GPIOB_ODR,Copy_u8Pin);
											
								} 
										
              else   
                    if (Copy_u8Value == GPIO_LOW){
											
										  CLEAR_BIT(GPIOB_ODR,Copy_u8Pin);			
	 							}
	                 break;
								
								
    case GPIOC :
		
                    if (Copy_u8Value == GPIO_HIGH ){
											
											SET_BIT(GPIOC_ODR,Copy_u8Pin);
											
								} 
										
              else   
                    if (Copy_u8Value == GPIO_LOW){
											
										  CLEAR_BIT(GPIOC_ODR,Copy_u8Pin);			
	 							}
	                 break;



	}


}


                                 /*FUNCTION TO GET THE PIN VALUE*/


uint8 GPIO_VoidGetPinValue(uint8 Copy_u8Port,uint8 Copy_u8Pin){

uint8 Result_Value = 0 ;
            

              switch (Copy_u8Port)
{
  
  	case GPIOA :   
                   Result_Value = GET_BIT(GPIOA_IDR,Copy_u8Pin);
	                 break;
    case GPIOB :
		
                   Result_Value = GET_BIT(GPIOB_IDR,Copy_u8Pin);
	                 break;
    case GPIOC :
                   Result_Value = GET_BIT(GPIOC_IDR,Copy_u8Pin);
	                 break;
	}
                   return Result_Value;
	
}


void GPIO_Void_Increment_value(uint8 Copy_u8Port){

   Seven_seg_counter = Seven_seg_counter + 1 ; 	
	
	              switch (Copy_u8Port)
								{

    case GPIOA :   
			              
                    GPIOA_ODR &= ~(0X0000002E);
		                GPIOA_ODR |=  (Seven_seg_counter  << 1);
		
		  
	                  break;
    case GPIOB :
		 
	
                    GPIOB_ODR|= (0X00000010);
		
		          		
		
		            // if(GPIO_VoidGetPinValue(GPIOA,PIN1) == GPIO_LOW ){
		            //while(1){}
								//}
									 
		                   // GPIOB_ODR=9;
									 
									 


	                  break;
    case GPIOC : 
			
			              GPIOC_ODR =  GPIOC_ODR + 1 ;
	                  break;
	}

}

void GPIO_Void_Decrement_value(uint8 Copy_u8Port){
	
	    Seven_seg_counter = Seven_seg_counter - 1 ; 	

	
	              switch (Copy_u8Port)
								{

    case GPIOA :   
			
                    GPIOA_ODR &= ~(0X0000002E);
		                GPIOA_ODR |=  (Seven_seg_counter  << 1);	    
		
                		break;
    case GPIOB :
		 
	
                    GPIOB_ODR|= (0X00000012);
		
	                  break;
    case GPIOC :
			
			              GPIOC_ODR =  GPIOC_ODR - 1 ;
	                  break;
	}

}

                       /*delay function */
 void _delay_ms (uint16 counter){
 
	   for( uint16 i =0 ; i < counter; i++){
		
			
		      	for(uint16 j=0 ; j<counter ; j++){
			
			            // asm("NOP");
			       }
		
		
		  }

}














