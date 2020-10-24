/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:23/9/2020***********************************/
/***********version:1***************************************/
/*********Description:TFT DRIVER***********************/
/***********************************************************/


#ifndef TFT_PRIVATE_H
#define TFT_PRIVATE_H

#include "STD_TYPES.h" 
 
                                              /*PRIVATE FUNCTION*/

 void TFT_voidWriteCommand(uint8 Copy_uint8command); /*SET A0 PIN TO LOW*/ 

 void TFT_voidWriteData(uint8 Copy_uint8Data);  /*SET A0 PIN TO HIGH*/
 

#endif
