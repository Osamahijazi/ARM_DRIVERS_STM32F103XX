/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:17/9/2020***********************************/
/***********Description:SPI DRIVER**************************/
/***********************************************************/
#include "STD_TYPES.h"
#include "MATH_BIT.h"
#include "GPIO_interface.h"
#include "SYSTIMER_Interface.h"
#include "SPI_Private.h"
#include "SPI_Config.h"
#include "SPI_Interface.h"

/* Define Callback Global Variable TO RESTORE THE RECEIVED VALUE */
 uint16 *SPI_CallBack;

void SPI1_voidInit(void){                     /*SPI1 Init*/

                                                /*Configuration of low 8bits is fixed*/
	
SPI->CR1 = CR1_COMMON_CONFIG;      
	
	                                              /*adjust fram format */

	#if    FRAM_FORMAT == LSB_FIRST
	SET_BIT(SPI->CR1,LSB);
	#elif  FRAM_FORMAT == MSB_FIRST
	CLEAR_BIT(SPI->CR1,MSB);
	#endif
	                                               /*adjust Baud Rate Control*/
	#if    BAUD_RATE_CONTROL == ClLOCK_FREQUENCY/64
	SET_BIT(SPI->CR1,BD1);
	CLEAR_BIT(SPI->CR1,BD2);
	SET_BIT(SPI->CR1,BD3);
	#elif   BAUD_RATE_CONTROL == ClLOCK_FREQUENCY/2
  CLEAR_BIT(SPI->CR1,BD1);
	CLEAR_BIT(SPI->CR1,BD2);
	CLEAR_BIT(SPI->CR1,BD3);
	#elif   BAUD_RATE_CONTROL == ClLOCK_FREQUENCY/4
  SET_BIT(SPI->CR1,BD1)  ;
	CLEAR_BIT(SPI->CR1,BD2);
	CLEAR_BIT(SPI->CR1,BD3);
	#elif   BAUD_RATE_CONTROL == ClLOCK_FREQUENCY/8
	CLEAR_BIT(SPI->CR1,BD1);
	SET_BIT(SPI->CR1,BD2)  ;
	CLEAR_BIT(SPI->CR1,BD3);
	#endif
	                                              /*ADJUST MASTER OR SLAVE SELECT*/
	#if    MASTER_SLAVE_SELECT == MASTER_ENABLE
	SET_BIT(SPI->CR1,MSTR);
	GPIO_VoidSetPinDirection(GPIOA,PIN4,OUTPUT_2MHZ_PP); /*NSS connected to ground  */
	#elif  MASTER_SLAVE_SELECT == SLAVE_ENABLE
	CLEAR_BIT(SPI->CR1,MSTR);
	CLEAR_BIT(SPI->CR1,SLAVE_SELECT_PIN);   /*SLAVE MODE SO ENABLE NSS*/
	GPIO_VoidSetPinDirection(GPIOA,PIN7,INPUT_PULL_UP_DOWN); /*MOSI----> INPUT DATA FROM MASTER TO SLAVE*/

	
	#endif
                                              	/*ADJUSTING THE CLOCK PERIORITY */
	#if    CLOCK_POLARITY == PER_LOW
	CLEAR_BIT(SPI->CR1,CPOL);
	#elif  CLOCK_POLARITY == PER_HIGH
	SET_BIT(SPI->CR1,CPOL);
	#endif
	
	                                             	/*ADJUSTING THE CLOCK PHASE */
	#if    CLOCK_PHASE == PH_HIGH
	SET_BIT(SPI->CR1,CPHA);
	#elif  CLOCK_PHASE == PH_LOW
	CLEAR_BIT(SPI->CR1,CPHA);
	#endif
	                                               /*Transmit and Receive Interrupt*/
																								 
	#if    TRANSMIT_INTERRUPT == ENABLE_TRANSMIT_INTERRUPT
	SET_BIT(SPI->CR2,TXEIE);
	#elif  TRANSMIT_INTERRUPT == DISABLE_TRANSMIT_INTERRUPT
	CLEAR_BIT(SPI->CR2,TXEIE);
	#endif
	
	#if    RECEIVE_INTERRUPT == ENABLE_RECEIVE_INTERRUPT
	SET_BIT(SPI->CR2,RXNEIE);
	#elif  RECEIVE_INTERRUPT == DISABLE_RECEIVE_INTERRUPT
	CLEAR_BIT(SPI->CR2,RXNEIE);
	#endif
	
                                                /*ENABLE SPI*/
SET_BIT(SPI->CR1,SPI_ENABLE);


}
/*********************************************************************************************************************************************************************************************************************************************************/

                          /************THIS FUNCTION TAKE THE TRANSMIT VALUE AND RETURN THE RECEIVED DATA*********************/

/*********************************************************************************************************************************************************************************************************************************************************/
uint16 SPI1_uint16SendReceiveSynch(uint16 Copy_uint8DataToTransmit){
                                     
	                                         /*SEND DATA*/
	SPI->DR = Copy_uint8DataToTransmit;
	
                                         	/*WAIT UNTIL SPI IS NOT BUSY*/
	while(BIT_IS_SET(SPI->SR,SPI_IS_BUSY));
	
	return  (SPI->DR) ;                  /*Get Recived Data*/
}

/*********************************************************************************************************************************************************************************************************************************************************/

               /************THIS FUNCTION TAKE THE TRANSMIT VALUE AND THE VARIABLE IN WHICH WE STORE RECIEVED DATA AFTER INTERRUPT ACCUR*********************/

/*********************************************************************************************************************************************************************************************************************************************************/

void SPI1_voidSendReceiveAsynch(uint16 Copy_uint16DataToTransmit,uint16 *Callback){  /*Send and lately Receive by interrupt*/
	                                                 /*SEND DATA*/
	SPI->DR = Copy_uint16DataToTransmit;
	
		/* Save CallBack  */
	SPI_CallBack = Callback ;
}

/*********************************************************************************************************************************************************************************************************************************************************/

void SPI1_IRQHandler(void){
	
	*SPI_CallBack= (SPI->DR) ;  /*Get THE RECEIVED Data STORED IN RX BUFFER*/
	}