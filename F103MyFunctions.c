#include "F103MyFunctions.h"
#include "stm32f10x.h"

void GPIO_PP_L_Init(uint32_t RCC_GPIOx, uint16_t Pinx, GPIO_TypeDef *GPIOx)
{
    GPIO_InitTypeDef GPIO_ITD;
    RCC_APB2PeriphClockCmd(RCC_GPIOx, ENABLE);
    GPIO_ITD.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_ITD.GPIO_Speed = GPIO_Speed_10MHz;
    GPIO_ITD.GPIO_Pin = Pinx;
    GPIO_Init(GPIOx, &GPIO_ITD);
    GPIO_WriteBit(GPIOx, Pinx, Bit_RESET);
}
void GPIO_PP_H_Init(uint32_t RCC_GPIOx, uint16_t Pinx, GPIO_TypeDef *GPIOx)
{
    GPIO_InitTypeDef GPIO_ITD;
    RCC_APB2PeriphClockCmd(RCC_GPIOx, ENABLE);
    GPIO_ITD.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_ITD.GPIO_Speed = GPIO_Speed_10MHz;
    GPIO_ITD.GPIO_Pin = Pinx;
    GPIO_Init(GPIOx, &GPIO_ITD);
    GPIO_WriteBit(GPIOx, Pinx, Bit_SET);
}
void GPIO_In_PD_Init(uint32_t RCC_GPIOx, uint16_t Pinx, GPIO_TypeDef *GPIOx)
{
    GPIO_InitTypeDef GPIO_ITD;
    RCC_APB2PeriphClockCmd(RCC_GPIOx, ENABLE);
    GPIO_ITD.GPIO_Mode = GPIO_Mode_IPD;
    GPIO_ITD.GPIO_Speed = GPIO_Speed_10MHz;
    GPIO_ITD.GPIO_Pin = Pinx;
    GPIO_Init(GPIOx, &GPIO_ITD);
}
void GPIO_In_PU_Init(uint32_t RCC_GPIOx, uint16_t Pinx, GPIO_TypeDef *GPIOx)
{
    GPIO_InitTypeDef GPIO_ITD;
    RCC_APB2PeriphClockCmd(RCC_GPIOx, ENABLE);
    GPIO_ITD.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_ITD.GPIO_Speed = GPIO_Speed_10MHz;
    GPIO_ITD.GPIO_Pin = Pinx;
    GPIO_Init(GPIOx, &GPIO_ITD);
}
