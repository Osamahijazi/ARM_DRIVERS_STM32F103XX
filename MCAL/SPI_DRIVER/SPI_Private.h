/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:17/9/2020***********************************/
/***********version:1***************************************/
/***********************************************************/

#ifndef SPI_Private_H
#define SPI_Private_H

#include "STD_TYPES.h"

/*********************************************************************************************************************************************************************************************************************************************************/
 /************************************************************SPI1 REISTER DEFINITIONS********************************************************************************************************************************************************************/
 typedef struct 
 {
   volatile uint32 CR1    ;
   volatile uint32 CR2    ;
   volatile uint32 SR     ;
   volatile uint32 DR     ;
   volatile uint32 CRCPR  ;
   volatile uint32 RXCRCR ;
   volatile uint32 TXCRCR ; 
   volatile uint32 I2SCFGR;
   volatile uint32 I2SPR  ;
  
 }SPI_t;	 

 
                          /*Pionter to SPI1 Registers Structure*/

#define     SPI       ((SPI_t*)0X40013000)
/*********************************************************************************************************************************************************************************************************************************************************/

                                                 /*CR1 PRIVATE MACROS*/

 #define        LSB_FIRST             0
 #define        MSB_FIRST             1
 #define           LSB                7
 #define           MSB                7
 #define           BD1                3
 #define           BD2                4
 #define           BD3                5
 #define        MASTER_ENABLE         0 
 #define        SLAVE_ENABLE          1
 #define          MSTR                2
 #define         PER_LOW              0
 #define         PER_HIGH             1
 #define         CPOL                 1
  #define         PH_LOW              0
 #define          PH_HIGH             1
 #define         CPHA                 0
 #define       SPI_ENABLE             6   
 #define     SLAVE_SELECT_PIN         9

 /*********************************************************************************************************************************************************************************************************************************************************/
                                                 /*CR2 PRIVATE MACROS*/
																								 
																								 
#define    ENABLE_TRANSMIT_INTERRUPT          0
#define    DISABLE_TRANSMIT_INTERRUPT         1
#define    DISABLE_RECEIVE_INTERRUPT          0
#define    ENABLE_RECEIVE_INTERRUPT           1
#define             TXEIE                     7
#define             RXNEIE                    6 
/*********************************************************************************************************************************************************************************************************************************************************/
                                                /*SR PRIVATE MACROS*/

#define             TXE                      1        /*TRANSMIT INTERRUPT FLAG*/
#define             RXNE                     0        /*RECIEVED INTERRUPT FLAG*/
#define         SPI_IS_BUSY                  7           /*BUSY SPI FLAG*/


#endif