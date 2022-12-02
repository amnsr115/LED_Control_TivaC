#include "Mcu_Hw.h"
#include "IntCtrl.h"
#include "Port.h"
#include "Dio.h"
#include "SysTick.h"
#include "Dio.h"

void BlinkLED(uint8 TimeON, uint8 TimeOFF);
void SystTick_ISR_Callback(void);
void PortF_ISR_Callback(void);



uint32 TimeON = 0;
uint32 TimeOFF = 0;




int main()
{
	Port_Init();
	Systick_Init();
	IntCrtl_Init();
	Dio_Add_Callback(PORTF, PortF_ISR_Callback);
	SysTick_Add_Callback(SystTick_ISR_Callback);
	

	BlinkLED(3,5);
	while(1)
	{

	}
}

void SystTick_ISR_Callback(void)
{
	SystickCounter++;
	if(SystickCounter < ((TimeON)*1000))
	{
		if( Dio_ReadChannel(PORTF, CHANNEL1) == LOW)
		{
		//Dio_WriteChannel(PORTF, CHANNEL1, HIGH);
		SETBIT(GPIO_PORTF_MOD_DATA_R,1);
		}

	}
	else if((SystickCounter < ((TimeOFF+TimeON)*1000 )))
	{
		if(Dio_ReadChannel(PORTF, CHANNEL1)== HIGH)
		{
		//Dio_WriteChannel(PORTF, CHANNEL1, LOW);
		CLEARBIT(GPIO_PORTF_MOD_DATA_R,1);
		}
	}
	
	else if (SystickCounter > ((TimeOFF+TimeON)*1000 ))
	{
		SystickCounter = 0;
	}
}


void PortF_ISR_Callback(void)
{
	
	if((GPIO_PORTF_MIS_R>>0 & 0x1) == HIGH)
	{
	TimeON++;
	TimeOFF--;
	}
	else if((GPIO_PORTF_MIS_R>>4 & 0x1) == HIGH)
	{
	TimeON--;
	TimeOFF++;
	}
	GPIO_PORTF_ICR_R = 0x11;

}

void BlinkLED(uint8 TON, uint8 TOFF)
{

	TimeON = TON;
	TimeOFF = TOFF;
	SystickCounter = 0;

}

