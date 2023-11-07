/*
 * MTIM_Interface.h
 *
 * Created on: Nov 4, 2023
 * Author: AbdElrhman Mamdouh
 */

#ifndef MTIM_INTERFACE_H_
#define MTIM_INTERFACE_H_

// Define a data structure to configure a timer
typedef struct {
    u16 u16ReloadValue;    // The value to reload the timer with
    u8 u8TimerID;          // An identifier for the timer (e.g., TIMER_1, TIMER_2)
    u8 u8CountDir;         // Timer count direction (TIMERS_DIRECTION_UP or TIMERS_DIRECTION_DOWN)
    u8 u8Interrupt;        // Timer interrupt source (e.g., TIMERS_INTERRUPT_UPDATE)
    void (*ptrFCalback)(void);  // A function pointer to the callback function for the timer
} TIMERConfig_t;

// Function to initialize a timer with the provided configuration
void MTIMERS_voidInit(TIMERConfig_t *TIMERConfig);

// Function to set the callback function for a specific timer
void MTIMERS_voidPutISRFunction(u8 copy_u8TimerID, void (*ptrF)(void));

// Function to set the reload value for a specific timer
void MTIMERS_voidSetReloadValue(u8 copy_u8TimerID, u16 copy_u16Value);

// Function to enable a specific timer
void MTIMERS_voidEnableTimer(u8 copy_u8TimerID);

// Function to disable a specific timer
void MTIMERS_voidDisableTimer(u8 copy_u8TimerID);

// Function to enable a specific timer interrupt
void MTIMERS_voidEnableInterrupt(u8 copy_u8TimerID, u8 copy_u8Interrupt);

// Timer identifiers
#define TIMER_1 1
#define TIMER_2 2
#define TIMER_3 3
#define TIMER_4 4

// Timer count directions
#define TIMERS_DIRECTION_UP 0
#define TIMERS_DIRECTION_DOWN 1

// Timer interrupt sources
#define TIMERS_INTERRUPT_UPDATE 0
#define TIMERS_INTERRUPT_CAPTCOMP1 1
#define TIMERS_INTERRUPT_CAPTCOMP2 2
#define TIMERS_INTERRUPT_CAPTCOMP3 3
#define TIMERS_INTERRUPT_CAPTCOMP4 4

#endif /* MTIM_INTERFACE_H_ */
