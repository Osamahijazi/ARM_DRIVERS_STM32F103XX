/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:20/8/2020***********************************/
/***********version:1***************************************/
/***********************************************************/
#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

# define NVIC_ISER0      *((uint32*)0XE000E100)
# define NVIC_ISER1      *((uint32*)0XE000E104)


# define NVIC_ICER0      *((uint32*)0XE000E180)
# define NVIC_ICER1      *((uint32*)0XE000E184)


# define NVIC_ISPR0      *((uint32*)0XE000E200)
# define NVIC_ISPR1      *((uint32*)0XE000E204)



# define NVIC_ICPR0      *((uint32*)0XE000E280)
# define NVIC_ICPR1      *((uint32*)0XE000E284)


# define NVIC_IABR0     *((volatile uint32*)0XE000E300)
# define NVIC_IABR1     *((volatile uint32*)0XE000E304)
	

# define NVIC_IPR        ((volatile uint8*)0XE000E400)       /* Pionter to first interrupt of the regiter*/

 
# define SCB_AIRCR       *((volatile uint32*)0XE000ED0C)     /*Registr used to set Group and Sub priority */





#define         NVIC_GROUP_4_SUB_0      0X05FA0300        4 BITS for Group (IPR) --> GROUP       
#define         NVIC_GROUP_3_SUB_1      0X05FA0400        3 BITS for Group & 1 BIT for sub Group 
#define         NVIC_GROUP_2_SUB_2      0X05FA0500        2 BITS for Group & 2 BIT for sub Group 
#define         NVIC_GROUP_1_SUB_3      0X05FA0600        1 BITS for Group & 3 BIT for sub Group  
#define         NVIC_GROUP_0_SUB_4      0X05FA0700        0 BITS for Group & 4 BIT for sub Group 

                                           /*EXTERNAL INTERRUPT  SOFTWARE NUMBER*/

#define         EXTI0                   6
#define         EXTI1                   7
#define         EXTI2                   8
#define         EXTI3                   9
#define         EXTI4                   10











#endif