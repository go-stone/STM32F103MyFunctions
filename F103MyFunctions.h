#include "stm32f10x.h"
void GPIO_PP_L_Init(uint32_t RCC_GPIOx, uint16_t Pinx, GPIO_TypeDef *GPIOx);
void GPIO_PP_H_Init(uint32_t RCC_GPIOx, uint16_t Pinx, GPIO_TypeDef *GPIOx);
void GPIO_In_PD_Init(uint32_t RCC_GPIOx, uint16_t Pinx, GPIO_TypeDef *GPIOx);
void GPIO_In_PU_Init(uint32_t RCC_GPIOx, uint16_t Pinx, GPIO_TypeDef *GPIOx);
