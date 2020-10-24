/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:23/9/2020***********************************/
/***********version:1***************************************/
/*********Description:TFT DRIVER***********************/
/***********************************************************/


#ifndef TFT_INTERFACE_H
#define TFT_INTERFACE_H

#include "STD_TYPES.h"


void TFT_voidInit   (void);/*TFT Init*/

void TFT_voidDisplayImage (const uint16* Copy_Image);/*GET IMAGES SAVED IN FLASH*/
void TFT_voidWriteCommand(uint8 Copy_uint8command); /*SET A0 PIN TO LOW*/ 

 void TFT_voidWriteData(uint8 Copy_uint8Data);  /*SET A0 PIN TO HIGH*/
 
void TFT_voidFillColor ( uint16 Copy_Color);/*DRAW SPECIFIC COLORS*/

void TFT_voidDrawRecrtan (uint8 x1,uint8 x2,uint8 y1,uint8 y2, uint16 Copy_Color);/*DRAW SPECIFIC COLORS*/




#endif