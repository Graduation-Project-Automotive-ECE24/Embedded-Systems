/*
 * MGPIO_private.h
 *
 *  Created on: Oct 23, 2023
 *      Author: pc castle
 */

#ifndef MCAL_MGPIO_MGPIO_PRIVATE_H_
#define MCAL_MGPIO_MGPIO_PRIVATE_H_


#define CNF_PIN_SHIFTING           2u


#define GPIO_PERIPPHERAL_NUM       8u

#define CR_MASK                    0b11
#define CR_PIN_ACCESS              4u
#define CR_PIN_SHIFTING            8u

#define ODR_MASK                   0b1

#define BSRR_MASK                  0b1
#define BSRR_PIN_SHIFTING          16u


#define IDR_MASK                  0b1

#define EVCR_PORT_MASK            0b111
#define EVCR_PIN_MASK             0b1111
#define EVCR_PIN_SHIFTING         4u
#define ECVR_PIN_ENABLE           1
#define ECVR_ENABLE_SHIFTING      7u


#define EXTI_MASK                 0b1111
#define EXTI_PIN_ACCESS           4u
#define EXTI_PIN_SHIFTING         4u

#endif /* MCAL_MGPIO_MGPIO_PRIVATE_H_ */
