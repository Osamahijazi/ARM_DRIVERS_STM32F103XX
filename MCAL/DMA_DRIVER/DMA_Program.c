/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:13/9/2020***********************************/
/***********version:1***************************************/
/*********Description:DMA REGISTERS***********************/
/***********************************************************/
#include "STD_TYPES.h"
#include "MATH_BIT.h"
#include "DMA_Private.h"
#include "DMA_Config.h"
#include "GPIO_interface.h"
#include "DMA_Interface.h"


void DMA_VoidChannelInit(void){

	                                                         /*ENABLE CHANNELS*/
  #if Channel_ID == First 
	SET_BIT(DMA->Channel[Channel_ID].CCR,DMA_ENABLE);
	#elif Channel_ID == Second 
	SET_BIT(DMA->Channel[Channel_ID].CCR,DMA_ENABLE);
	#elif Channel_ID == Third 
	SET_BIT(DMA->Channel[Channel_ID].CCR,DMA_ENABLE);
	#elif Channel_ID == Fourth 
	SET_BIT(DMA->Channel[Channel_ID].CCR,DMA_ENABLE);
	#elif Channel_ID == Fifth 
	SET_BIT(DMA->Channel[Channel_ID].CCR,DMA_ENABLE);
	#elif Channel_ID == Sixth 
	SET_BIT(DMA->Channel[Channel_ID].CCR,DMA_ENABLE);
	#elif Channel_ID == Sevth 
	SET_BIT(DMA->Channel[Channel_ID].CCR,DMA_ENABLE);
	#endif
	                                                        /*Memory Mode Configuration*/
 #if Mem_To_Mem_Mode == ENABLE 
 SET_BIT(DMA->Channel[Channel_ID].CCR,MEM2MEM);
 #elif Mem_To_Mem_Mode == DISABLE 
 CLEAR_BIT(DMA->Channel[Channel_ID].CCR,MEM2MEM);
 #endif
	                                                  /*CHANNEL PERIORITY   "very high - high - meduim - low"*/
  #if Channel_Periority == very_high 
	SET_BIT(DMA->Channel[Channel_ID].CCR,PL1);
	SET_BIT(DMA->Channel[Channel_ID].CCR,PL2);
	#elif Channel_Periority == high  
	CLEAR_BIT(DMA->Channel[Channel_ID].CCR,PL1);
	SET_BIT(DMA->Channel[Channel_ID].CCR,PL2);
	#elif Channel_Periority == meduim 
	SET_BIT(DMA->Channel[Channel_ID].CCR,PL1);
	CLEAR_BIT(DMA->Channel[Channel_ID].CCR,PL2);
	#elif Channel_Periority == low 
	CLEAR_BIT(DMA->Channel[Channel_ID].CCR,PL1);
	CLEAR_BIT(DMA->Channel[Channel_ID].CCR,PL2);
	#endif
	                                                           /*CHANNEL CICULARITY */

 #if Circular_Mode == ENABLE 
 SET_BIT(DMA->Channel[Channel_ID].CCR,CIRC);
 #elif Circular_Mode == DISABLE 
 CLEAR_BIT(DMA->Channel[Channel_ID].CCR,CIRC);
 #endif
	
	                                                      /*Memory size configuration */

 #if Memory_Size == ONE_BYTE 
 CLEAR_BIT(DMA->Channel[Channel_ID].CCR,MSIZE1);
 CLEAR_BIT(DMA->Channel[Channel_ID].CCR,MSIZE2);
 #elif Memory_Size == TWO_BYTE 
 SET_BIT(DMA->Channel[Channel_ID].CCR,MSIZE1);
 CLEAR_BIT(DMA->Channel[Channel_ID].CCR,MSIZE2);
 #endif
	 
	                                                 /*Peripheral size configuration */

 #if Memory_Size == ONE_BYTE 
 CLEAR_BIT(DMA->Channel[Channel_ID].CCR,PSIZE1);
 CLEAR_BIT(DMA->Channel[Channel_ID].CCR,PSIZE2);
 #elif Memory_Size == TWO_BYTE 
 SET_BIT(DMA->Channel[Channel_ID].CCR,PSIZE1);
 CLEAR_BIT(DMA->Channel[Channel_ID].CCR,PSIZE2);
 #endif

                                                       /*Memory INCREMENT */

 #if Memory_Increment_mode == DISABLE 
 CLEAR_BIT(DMA->Channel[Channel_ID].CCR,MINC);
 #elif Memory_Increment_mode == ENABLE 
 SET_BIT(DMA->Channel[Channel_ID].CCR,MINC);
 #endif
	
	                                                    /*Peripheral INCREMENT */

 #if Peripheral_Increment_mode == DISABLE 
 CLEAR_BIT(DMA->Channel[Channel_ID].CCR,MINC);
 #elif Peripheral_Increment_mode == ENABLE 
 SET_BIT(DMA->Channel[Channel_ID].CCR,MINC);
 #endif
	
                                                     /*Data Direction */

 #if DATA_DIRECTION == ENABLE 
 SET_BIT(DMA->Channel[Channel_ID].CCR,DIR);
 #elif DATA_DIRECTION == DISABLE 
 CLEAR_BIT(DMA->Channel[Channel_ID].CCR,DIR);
 #endif	
	
	                                          /*Transfer complete interrupt enable */

 #if TRANSFER_INTERRUPT == ENABLE 
 SET_BIT(DMA->Channel[Channel_ID].CCR,TCIE);
 #elif TRANSFER_INTERRUPT == DISABLE 
 CLEAR_BIT(DMA->Channel[Channel_ID].CCR,TCIE);
 #endif	
}

void DMA_VoidChannelStart(uint32*Copy_ptr32SourceAddress,uint32*Copy_ptr32DestinationAddress,uint16 Copy_uint16BlockLenght){
	
                                 /*FIRST WE DISABLE CHANNEL BEFIRE WRITE ADDRESSES */
CLEAR_BIT(DMA->Channel[Channel_ID].CCR,DMA_ENABLE);

                                              /* WRITE ADDRESSES */
DMA->Channel[Channel_ID].CPAR  = Copy_ptr32SourceAddress;
DMA->Channel[Channel_ID].CMAR  = Copy_ptr32SourceAddress;
                                             /* WRITE BLOCK LENGHT*/
DMA->Channel[Channel_ID].CNDTR = Copy_uint16BlockLenght;
	
                                              /* ENABLE CHANNEL */
SET_BIT(DMA->Channel[Channel_ID].CCR,DMA_ENABLE);

}






