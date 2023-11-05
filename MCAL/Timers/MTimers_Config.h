/*
 * MTIM_Config.h
 *
 *  Created on: Nov 4, 2023
 *      Author: AbdElrhman Mamdouh
 */

#ifndef MTIM_CONFIG_H_
#define MTIM_CONFIG_H_

typedef struct {
	u16 u16ReloadValue;
	u8 u8TimerID;
	u8 u8CountDir;
	u8 u8Interrupt;
	void (*ptrFCalback) (void);
}TIMERConfig_t;

/************************** TIMER1 *********************************/

/************************** TIMER2 *********************************/

/************************** TIMER3 *********************************/

/************************** TIMER4 *********************************/


#endif /* MTIM_CONFIG_H_ */
