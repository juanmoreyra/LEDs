/*
 * LEDs.c
 *
 *  Created on: Oct 5, 2022
 *      Author: Barcala
 */
#include "LEDs.h"
//#include "stm32f1xx_hal_gpio.h"

void LED_Init(LED_Handler_t LED){
	if (LED.LED_PP.LED_Pin == 0) {
		LED.LED_PP.LED_Pin = GPIO_PIN_0;
	}
	if (LED.LED_PP.LED_Pin == 1) {
		LED.LED_PP.LED_Pin = GPIO_PIN_1;
	}
	if (LED.LED_PP.LED_Pin == 2) {
		LED.LED_PP.LED_Pin = GPIO_PIN_2;
	}
	if (LED.LED_PP.LED_Pin == 3) {
		LED.LED_PP.LED_Pin = GPIO_PIN_3;
	}
	if (LED.LED_PP.LED_Pin == 4) {
		LED.LED_PP.LED_Pin = GPIO_PIN_4;
	}
	if (LED.LED_PP.LED_Pin == 5) {
		LED.LED_PP.LED_Pin = GPIO_PIN_5;
	}
	if (LED.LED_PP.LED_Pin == 6) {
		LED.LED_PP.LED_Pin = GPIO_PIN_6;
	}
	if (LED.LED_PP.LED_Pin == 7) {
		LED.LED_PP.LED_Pin = GPIO_PIN_7;
	}
	if (LED.LED_PP.LED_Pin == 8) {
		LED.LED_PP.LED_Pin = GPIO_PIN_8;
	}
	if (LED.LED_PP.LED_Pin == 9) {
		LED.LED_PP.LED_Pin = GPIO_PIN_9;
	}
	if (LED.LED_PP.LED_Pin == 10) {
		LED.LED_PP.LED_Pin = GPIO_PIN_10;
	}
	if (LED.LED_PP.LED_Pin == 11) {
		LED.LED_PP.LED_Pin = GPIO_PIN_11;
	}
	if (LED.LED_PP.LED_Pin == 12) {
		LED.LED_PP.LED_Pin = GPIO_PIN_12;
	}
	if (LED.LED_PP.LED_Pin == 13) {
		LED.LED_PP.LED_Pin = GPIO_PIN_13;
	}
	if (LED.LED_PP.LED_Pin == 14) {
		LED.LED_PP.LED_Pin = GPIO_PIN_14;
	}
	if (LED.LED_PP.LED_Pin == 15) {
		LED.LED_PP.LED_Pin = GPIO_PIN_15;
	}
}

//LED_ON APAGA el LED cuando está en lógica invertida
void LED_ON(LED_Handler_t LED){
	if (LED.LED_Logic == LED_LOG_DIRECTA) {
		HAL_GPIO_WritePin(LED.LED_PP.LED_Port, LED.LED_PP.LED_Pin, GPIO_PIN_RESET);
		LED.LED_State = LED_ENCENDIDO;
	}
	if (LED.LED_Logic == LED_LOG_INVERTIDA) {
		HAL_GPIO_WritePin(LED.LED_PP.LED_Port, LED.LED_PP.LED_Pin, GPIO_PIN_SET);
		LED.LED_State = LED_APAGADO;
	}
}

//LED_OFF ENCIENDE el LED cuando está en lógica invertida
void LED_OFF(LED_Handler_t LED){
	if (LED.LED_Logic == LED_LOG_DIRECTA) {
		HAL_GPIO_WritePin(LED.LED_PP.LED_Port, LED.LED_PP.LED_Pin, GPIO_PIN_SET);
		LED.LED_State = LED_APAGADO;
	}
	if (LED.LED_Logic == LED_LOG_INVERTIDA) {
		HAL_GPIO_WritePin(LED.LED_PP.LED_Port, LED.LED_PP.LED_Pin, GPIO_PIN_RESET);
		LED.LED_State = LED_ENCENDIDO;
	}
}

void LED_TOGGLE(LED_Handler_t LED){
	if(LED.LED_State == LED_ENCENDIDO){
			HAL_GPIO_TogglePin(LED.LED_PP.LED_Port,LED.LED_PP.LED_Pin);
			LED.LED_State = LED_APAGADO;
	}
	if(LED.LED_State == LED_APAGADO){
			HAL_GPIO_TogglePin(LED.LED_PP.LED_Port,LED.LED_PP.LED_Pin);
			LED.LED_State = LED_ENCENDIDO;
	}
}

void LED_Desinit(LED_Handler_t LED){

	LED.LED_State = LED_NOINIT;
}
