/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:17/9/2020***********************************/
/***********version:1***************************************/
/***********************************************************/

#ifndef SPI_Interface_H
#define SPI_Interface_H
#include "STD_TYPES.h"


void   SPI1_voidInit(void);      /*Init Configuration*/

uint16 SPI1_voidSendReceiveSynch(uint16 Copy_uint8DataToTransmit); /*Sent Data and receive it */

void SPI1_voidSendReceiveAsynch(uint16 Copy_uint16DataToTransmit,uint16 *Callback);  /*Send and lately Receive by interrupt*/

void   SPI1_IRQHandler(void); /*interrupt Handler after Receiving Data*/



#endif