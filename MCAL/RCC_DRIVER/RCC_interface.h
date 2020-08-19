#include "STD_TYPES.h"

#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H


#define RCC_AHB   0
#define RCC_APB1  1
#define RCC_APB2  2



  void RCC_InitysClock(void);
	
	void RCC_VoidEnableClock(uint8,uint8);

#endif