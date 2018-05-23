#include "LPC11xx.h"
unsigned int status;
/********************************************************
*FunctiongName:LedInit()
*Description  :初始化LED引脚
*EntryParameter:None
*RetuenValue： None
*******************************************************/
void LedInit(void)
{
LPC_SYSCON->SYSAHBCLKCTRL |= (1<<16);
LPC_IOCON->PIO2_0 &= ~0x07;
LPC_IOCON->PIO2_0 |= 0x00;
LPC_IOCON->PIO2_1 &= ~0x07;
LPC_IOCON->PIO2_1 |= 0x00;
LPC_SYSCON->SYSAHBCLKCTRL &= ~(1<<16);
LPC_SYSCON->SYSAHBCLKCTRL |= (1<<6);
LPC_GPIO2->DIR |= (1<<0);
LPC_GPIO2->DATA |= (1<<0);
LPC_GPIO2->DIR |= (1<<1);
LPC_GPIO2->DATA |= (1<<1);
}

/****************************************************
*FuctionName :SysTickInit()
*Description :初始化系统节拍定时器
*EntryParameter :None
*RetuenValue ：None
*****************************************************/
void SysTickInit()
{
SysTick->CTRL &= ~(1<<2);
SysTick->LOAD = 12499999;
SysTick->VAL =0;
SysTick->CTRL  |= ((1<<1)|(1<<0));
NVIC_EnableIRQ(SysTick_IRQn);	
}

/*****************************************************
*FuctionName: SysTick_Handler()
*Descripption: 系统节拍定时器中断服务函数
*EntryParameter: None
*ReturnValue :None
*****************************************************/
void SysTick_Handler(void)
{
status = LPC_GPIO2->DATA;
LPC_GPIO2->DATA = ~status;
}
/****************************************************
*FunctionName: mian()
*Description: 主函数
*EntryParameter: None
*ReturnValue: None
*****************************************************/
int main()
{
LedInit();
SysTickInit();
while(1)
   {
}	

}	
