/*
 * main.c
 *
 * Created: 2/9/2024 10:44:16 AM
 * Author : George Eliadis
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


int main(void)
{
	/* Q1
	DDRB |= (1<<DDB1); // setting PB1 (pin 1 on B panel) to be an output
	DDRB |= (1<<DDB2);
	DDRB |= (1<<DDB3);
	DDRB |= (1<<DDB4);
	PORTB |= (1<<PORTB1);
	PORTB |= (1<<PORTB2);
	PORTB |= (1<<PORTB3);
	PORTB |= (1<<PORTB4);
	PORTB &= ~(1<<PORTB1);
	PORTB &= ~(1<<PORTB2);
	PORTB &= ~(1<<PORTB3);
	PORTB &= ~(1<<PORTB4);
	PORTB ^= (1<<PORTB1);
	PORTB ^= (1<<PORTB2);
	PORTB ^= (1<<PORTB3);
	PORTB ^= (1<<PORTB4);
	while (1) {
	}
	*/
	
	/* Q2
	DDRB |= (1<<DDB1);
	DDRB |= (1<<DDB2);
	DDRB |= (1<<DDB3);
	DDRB |= (1<<DDB4);
	DDRD &= ~(1<<DDD7); // input
		while (1) {
			if (PIND & (1<<PIND7)) {
				PORTB |= (1<<PORTB1);
				PORTB |= (1<<PORTB2);
				PORTB |= (1<<PORTB3);
				PORTB |= (1<<PORTB4);
					} else {
				PORTB &= ~(1<<PORTB1);
				PORTB &= ~(1<<PORTB2);
				PORTB &= ~(1<<PORTB3);
				PORTB &= ~(1<<PORTB4);		
					}
			}
	*/
	
	/* Q3
	DDRB |= (1<<DDB1);
	DDRB |= (1<<DDB2);
	DDRB |= (1<<DDB3);
	DDRB |= (1<<DDB4);
	DDRD &= ~(1<<DDD7); // input
	int counter = 1;
	while (1)
	{
		if (PIND & (1<<PIND7)){
			if (counter == 1)
			{
				PORTB |= (1<<PORTB2); // 2 on
				PORTB &= ~(1<<PORTB1); // 1 off
			}
			if (counter == 2) {
				PORTB |= (1<<PORTB3); // 3 on
				PORTB &= ~(1<<PORTB2); // 2 off
			}
			if (counter == 3) {
				PORTB |= (1<<PORTB4); // 4 on
				PORTB &= ~(1<<PORTB3); // 3 off
			}
			if (counter == 4) {
				PORTB |= (1<<PORTB1);  // 1 off
				PORTB &= ~(1<<PORTB4); // 4 off
			}
			counter = counter % 4 + 1;
			_delay_ms(1000);
		}
	} */
}
	
	

