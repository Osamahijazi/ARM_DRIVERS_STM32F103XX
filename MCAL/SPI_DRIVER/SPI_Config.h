/***********************************************************/
/**********Author: osama hegazi*****************************/
/**********Date:17/9/2020***********************************/
/***********version:2***************************************/
/***********************************************************/

#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H

/***********************************************************************************************************************************************************************************************************************************************************/
                                                          /*CR1 REGISTER CONFIGURATION*/
                                                          /*please write port pin pair*/
					 

#define   CR1_COMMON_CONFIG        0X00000200      /*ALL LOW 8 BITS OF THE REGISTER ARE LOW*/
                                                    /*We only interested in high 8bits*/
											/*configuration of low 8bits: 
																										1-output enable in diffrent direction
																										2-CRC Calculation Disable
																										3-Data format = 8bit            
                                                    4-Slave selcet managed by softwareand NSS always connected to ground in master mode*/
                               
#define   SPI_ENABLE                  6   

                                    /*Choose sending Mode MSB_FIRST OR LSB_FIRST*/


#define   FRAM_FORMAT              LSB_FIRST

                                   /*Choose The Baud Rate*/
																	 
																	 /* F/2 = 000
																	    F/4 = 001
																			F/64 = 101 */
																			
#define   ClLOCK_FREQUENCY           1000000																			
#define   BAUD_RATE_CONTROL   			 ClLOCK_FREQUENCY/2														 
																	 
																	 /*MASTER SLAVE SELECTION*/
																	    /*(MASTER OR SLAVE_ENABLE)*/
																	
#define   MASTER_SLAVE_SELECT       MASTER_ENABLE
																	 
																	 
																	 /*CLOCK POLARITY */
                                   /* HIGH: LEADING EDGE IS LOW
																	    LOW : LEADING EDGE IS HIGH  */



#define  CLOCK_POLARITY            PER_LOW
																	 
																																		 
																	 /*CLOCK PHASE*/
																	 /* HIGH: WRITE THEN READ
																	    LOW : READ THE WRITE  */
																	 
#define  CLOCK_PHASE						   PH_HIGH			


/***********************************************************************************************************************************************************************************************************************************************************/
                                                          /*CR2 REGISTER CONFIGURATION*/
																													
                                                          
#define TRANSMIT_INTERRUPT             DISABLE_TRANSMIT_INTERRUPT		
#define RECEIVE_INTERRUPT              DISABLE_RECEIVE_INTERRUPT  /*ENABLE IT TO GET DATA USING INTERRUPT MODE*/
#define TRANSMIT_INTERRUPT_FLAG                TXE
#define RECEIVE_INTERRUPT_FLAG                 RXNE
	
	                                         		
		
#endif