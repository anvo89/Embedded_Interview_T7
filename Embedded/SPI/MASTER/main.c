#include "stm32f10x.h"

#define SCK GPIO_Pin_6
#define MOSI GPIO_Pin_7
#define SS GPIO_Pin_8
#define PORT GPIOB

void config(void);
void delay(unsigned int TIME);
void spiInit(void);
void clock(void);
void transmit(uint8_t data);

void delay(unsigned int TIME)
{
    unsigned int i, j;
    for (i = 0; i < TIME; i++)
        for (j = 0; j < 7998; j++)
            ;
}

void config(void)
{
    GPIO_InitTypeDef gpio;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    gpio.GPIO_Pin = SCK | MOSI | SS;
    gpio.GPIO_Mode = GPIO_Mode_Out_PP;
    gpio.GPIO_Speed = GPIO_Speed_2MHz;
    GPIO_Init(GPIOB, &gpio);
}

void spiInit(void)
{
    GPIO_ResetBits(PORT, SCK);
    GPIO_ResetBits(PORT, MOSI);
    GPIO_SetBits(PORT, SS);
}

void clock(void)
{
    GPIO_SetBits(GPIOB, SCK);
    delay(1000000);
    GPIO_ResetBits(GPIOB, SCK);
    delay(1000000);
}

void transmit(uint8_t data)
{
		unsigned int i;
    GPIO_ResetBits(GPIOB, SS);
    for (i = 0; i < 8; i++)
    {
        if (data & (1 << i))
            GPIO_SetBits(GPIOB, MOSI);
        else
            GPIO_ResetBits(GPIOB, MOSI);
        clock();
    }
    GPIO_ResetBits(GPIOB, SS);
}

int main(void)
{
		uint8_t data = 170;
    config();
    spiInit();
    transmit(data);
    return 0;
}
