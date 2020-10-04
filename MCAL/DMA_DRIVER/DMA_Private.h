/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:13/9/2020***********************************/
/***********version:1***************************************/
/*********Description:DMA DRIVER***********************/
/***********************************************************/


#ifndef DMA_PRIVATE_H
#define DMA_PRIVATE_H

#include "STD_TYPES.h"

#define NUMBER_OF_CHANNEL     7


typedef struct 
{

  volatile uint32 CCR   ;
	volatile uint32 CNDTR ;
	volatile uint32 CPAR  ;
	volatile uint32 CMAR  ;
	volatile uint32 Reserved ;

}DMA_Channel;

typedef struct 
{

	 volatile uint32 ISR  ;
	 volatile uint32 IFCR ;
   DMA_Channel Channel[NUMBER_OF_CHANNEL];	

}DMA_t;


#define   DMA      ((volatile DMA_t*)0x40020000)
	
/***********************************************************************************************************************************************************************************************************************************************************/
                                                    /*CCR REGISTER CONFIGURATION*/
#define   ENABLE              1
#define   DISABLE             0
#define   DMA_ENABLE          0
                                     /*CHANNEL PERIORITY   "very high - high - meduim - low"*/
#define   very_high           0
#define   high                1
#define   meduim              2
#define   low                 3
                                                  /*Channel ID CNFIGURATION*/																												
#define   First               0
#define   Second              1
#define   Third               2
#define   Fourth              3
#define   Fifth               4
#define   Sixth               5
#define   Sevth               6
/***********************************************************************************************************************************************************************************************************************************************************/
#define   ONE_BYTE            0
#define   TWO_BYTE            1
#define   READ_FROM_PERIPH    0
#define   READ_FROM_MEMORY    1
#define   MEM2MEM             14
#define   PL1                 12                   
#define   PL2                 13                   
#define   MSIZE1              10         /*MEMORY SIZE BITS*/                                
#define   MSIZE2              11                                   
#define   PSIZE1              8          /*PERIPHERAL SIZE BITS*/             
#define   PSIZE2              9                                   
#define   MINC                7          /*Memory increment mode*/
#define   PINC                6          /*Peripheral increment mode*/                               
#define   CIRC                5          /*Circular mode*/                         
#define   DIR                 4         /*DATA TRANSFER DIRECTION*/                             
#define   TCIE                1        /*TRANSFER COMPLETE INTERRUPT*/                             
/***********************************************************************************************************************************************************************************************************************************************************/






#endif 