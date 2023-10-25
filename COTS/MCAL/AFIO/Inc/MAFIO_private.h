/*
 * MAFIO_private.h
 *
 *  Created on: Oct 25, 2023
 *      Author: pc castle
 */

#ifndef MCAL_MAFIO_MAFIO_PRIVATE_H_
#define MCAL_MAFIO_MAFIO_PRIVATE_H_

#define EVCR_PORT_MASK            0b111
#define EVCR_PIN_MASK             0b1111
#define EVCR_PIN_SHIFTING         4u
#define ECVR_PIN_ENABLE           1
#define ECVR_ENABLE_SHIFTING      7u


#define EXTI_MASK                 0b1111
#define EXTI_PIN_ACCESS           4u
#define EXTI_PIN_SHIFTING         4u

#define MAPR_OneBit_MASK         0b1
#define MAPR_TwoBits_MASK        0b11
#define MAPR_PIN_SHIFTING        2u

#endif /* MCAL_MAFIO_MAFIO_PRIVATE_H_ */
