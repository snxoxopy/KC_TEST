/*
 * ex_1.c
 *
 * Created: 2018-11-07 오후 3:16:50
 * Author : kccistc
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>

volatile int int_tim = 0;
ISR(TIMER0_OVF_vect)
{
	int_tim++;
	int_tim %= 64;
}


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
		if(int_tim == 20) // 63 1초 20번 0.3초 
		{
			PORTA = 0xff;
		}
		else
		{
			PORTA = 0x00;
		}
	}
}
