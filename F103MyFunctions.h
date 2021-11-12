#include "stm32f10x.h"
void GPIO_PP_L_Init(uint32_t RCC_GPIOx, uint16_t Pinx, GPIO_TypeDef *GPIOx);
void GPIO_PP_H_Init(uint32_t RCC_GPIOx, uint16_t Pinx, GPIO_TypeDef *GPIOx);
void GPIO_In_PD_Init(uint32_t RCC_GPIOx, uint16_t Pinx, GPIO_TypeDef *GPIOx);
void GPIO_In_PU_Init(uint32_t RCC_GPIOx, uint16_t Pinx, GPIO_TypeDef *GPIOx);
void GPIO_In_Fl_Init(uint32_t RCC_GPIOx, uint16_t Pinx, GPIO_TypeDef *GPIOx);
void TIMx_Init(uint16_t RCC_TIMx, int APBx, TIM_TypeDef *TIMx, int psc, int prd);
void NVICx_Init(uint8_t IRQ_CH, int Main_pri, int Sub_pri);
void Toggle_Pin(GPIO_TypeDef *GPIOx, uint16_t Pinx);
