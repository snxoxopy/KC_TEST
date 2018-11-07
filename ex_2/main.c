/*
 * ex_2.c
 *
 * Created: 2018-11-07 오후 4:30:19
 * Author : usuzin
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#define LED_TOGGLE(x,y)		x ^= (1<<y)
#define LED_SET(x,y)		x |= (1<<y)
#define LED_CLEAR(x,y)		x &= ~(1<<y)

int AVR_init()
{
	DDRA |= 0xff;
    PORTA = 0x00;
	TCCR0 |= ((1<<CS02) | (1<<CS01) | (1<<CS00)); //1024 64 1초
	TIMSK |= (1 << TOIE0);
}

int main()
{
	AVR_init();
	sei();
	
	while(1)
	{
		//문제2번
		for(int i = 0; i<16; i++)
		{
			if(i<8)
			{
				LED_SET(PORTA,i);
				_delay_ms(300);
				LED_CLEAR(PORTA,i);
			}			
			else
			{
				LED_SET(PORTA,((i%8)-7)*(-1)); 
				_delay_ms(300);
				LED_CLEAR(PORTA,((i%8)-7)*(-1));
			}
		}
	}
}


