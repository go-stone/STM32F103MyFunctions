/**
 * @author ZhangYi
 * */
#include "F103MyFunctions.h"
#include "stm32f10x.h"
/**
 * @brief 将指定引脚初始化为输出低电平的推挽输出模式
 * @param RCC_GPIO外设，引脚编号，GPIOx
 * @retval void
 * */
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
/**
 * @brief 将指定引脚初始化为输出高电平的推挽输出模式
 * @param RCC_GPIO外设，引脚编号，GPIOx
 * @retval void
 * */
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
/**
 * @brief 将指定引脚初始化为下拉的输入模式
 * @param RCC_GPIO外设，引脚编号，GPIOx
 * @retval void
 * */
void GPIO_In_PD_Init(uint32_t RCC_GPIOx, uint16_t Pinx, GPIO_TypeDef *GPIOx)
{
    GPIO_InitTypeDef GPIO_ITD;
    RCC_APB2PeriphClockCmd(RCC_GPIOx, ENABLE);
    GPIO_ITD.GPIO_Mode = GPIO_Mode_IPD;
    GPIO_ITD.GPIO_Speed = GPIO_Speed_10MHz;
    GPIO_ITD.GPIO_Pin = Pinx;
    GPIO_Init(GPIOx, &GPIO_ITD);
}
/**
 * @brief 将指定引脚初始化为上拉的输入模式
 * @param RCC_GPIO外设，引脚编号，GPIOx
 * @retval void
 * */
void GPIO_In_PU_Init(uint32_t RCC_GPIOx, uint16_t Pinx, GPIO_TypeDef *GPIOx)
{
    GPIO_InitTypeDef GPIO_ITD;
    RCC_APB2PeriphClockCmd(RCC_GPIOx, ENABLE);
    GPIO_ITD.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_ITD.GPIO_Speed = GPIO_Speed_10MHz;
    GPIO_ITD.GPIO_Pin = Pinx;
    GPIO_Init(GPIOx, &GPIO_ITD);
}
/**
 * @brief 将指定引脚初始化为浮空输入模式
 * @param RCC_GPIO外设，引脚编号，GPIOx
 * @retval void
 * */
void GPIO_In_Fl_Init(uint32_t RCC_GPIOx, uint16_t Pinx, GPIO_TypeDef *GPIOx)
{
    GPIO_InitTypeDef GPIO_ITD;
    RCC_APB2PeriphClockCmd(RCC_GPIOx, ENABLE);
    GPIO_ITD.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_ITD.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_ITD.GPIO_Pin = Pinx;
    GPIO_Init(GPIOx, &GPIO_ITD);
}
/**
 * @brief 初始化指定的TIMx，需指定分频系数和计数周期
 * @param RCC_TIM外设，APBx时钟线，TIMx，分频系数，计数周期
 * @retval void
 * */
void TIMx_Init(uint16_t RCC_TIMx, int APBx, TIM_TypeDef *TIMx, int psc, int prd)
{
    TIM_TimeBaseInitTypeDef TIM_TBITD;
    if (APBx == 1)
    {
        RCC_APB1PeriphClockCmd(RCC_TIMx, ENABLE);
    }
    else if (APBx == 2)
    {
        RCC_APB2PeriphClockCmd(RCC_TIMx, ENABLE);
    }
    TIM_TBITD.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TBITD.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TBITD.TIM_Prescaler = psc - 1;
    TIM_TBITD.TIM_Period = prd - 1;
    TIM_TimeBaseInit(TIMx, &TIM_TBITD);
    TIM_ITConfig(TIMx, TIM_IT_Update, ENABLE);
    TIM_Cmd(TIMx, ENABLE);
}
/**
 * @brief 初始化指定通道的NVIC中断，需指定主次优先级
 * @param IRQ中断通道，主优先级，次优先级
 * @retval void
 * */
void NVICx_Init(uint8_t IRQ_CH, int Main_pri, int Sub_pri)
{
    NVIC_InitTypeDef NVIC_ITD;
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    NVIC_ITD.NVIC_IRQChannel = IRQ_CH;
    NVIC_ITD.NVIC_IRQChannelPreemptionPriority = Main_pri;
    NVIC_ITD.NVIC_IRQChannelSubPriority = Sub_pri;
    NVIC_ITD.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_ITD);
}
/**
 * @brief 翻转指定引脚的电平
 * @param GPIOx,引脚编号
 * @retval void
 * */
void Toggle_Pin(GPIO_TypeDef *GPIOx, uint16_t Pinx)
{
    if (GPIO_ReadOutputDataBit(GPIOx, Pinx) == Bit_SET)
    {
        GPIO_WriteBit(GPIOx, Pinx, Bit_RESET);
    }
    else if (GPIO_ReadOutputDataBit(GPIOx, Pinx) == Bit_RESET)
    {
        GPIO_WriteBit(GPIOx, Pinx, Bit_SET);
    }
}
