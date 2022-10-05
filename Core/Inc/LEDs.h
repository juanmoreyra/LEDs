/*
 * LEDs.h
 *
 *  Created on: Oct 5, 2022
 *      Author: Barcala
 */

#ifndef SRC_LEDS_H_
#define SRC_LEDS_H_
#include <stdint.h>
#include "stm32f1xx_hal.h"

typedef enum{
	LED_LOG_DIRECTA,LED_LOG_INVERTIDA
}LED_Logic_t;
typedef enum{
	LED_APAGADO,LED_ENCENDIDO,LED_NOINIT
}LED_State_t;

typedef struct{
	struct LED_Port_Pin{
		GPIO_TypeDef* LED_Port;
		uint16_t LED_Pin;
	}LED_PP;
	LED_Logic_t LED_Logic;
	LED_State_t LED_State;
} LED_Handler_t;

//Funcion que inicializa el LED. Recibe puerto, pin y logica
void LED_Init(LED_Handler_t LED);

void LED_ON(LED_Handler_t LED);
void LED_OFF(LED_Handler_t LED);
void LED_TOGGLE(LED_Handler_t LED);
//Funcion que desinicializa el LED. Deja el GPIO en modo flotante
void LED_Desinit(LED_Handler_t LED);

#endif /* SRC_LEDS_H_ */
