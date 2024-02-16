/*
 * partb.c
 *
 * Created: 2/9/2024 10:44:16 AM
 * Author : George Eliadis
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

void Initialize() {
	
	cli(); //disable global interrupts
	DDRB |= (1<<DDB3); //output
	DDRB &= ~(1<<DDB0); //input
	PORTB |= (1<<PORTB0);
	
	//set the appropriate edge control bits in TCCR1B
	TCCR1B |= (1<<ICES1); // rising edge
	
	// enable interrupt in TIMSK1 --> clearing input capture flag in TIFR1 by storing 1 in ICF1
	TIMSK1 |= (1<<ICIE1);
	
	// reading PORTB, declared as PINB, will determine button depression
	// looking for rising edge in B0
	//PORTB |= (PINB & (1<<PORTD7));
	
	//PCICR |= (1<<PCIE2);
	//PCMSK2 |= (1<<PCINT21);
	sei();
}

ISR(TIMER_1_CAPT_vect) {
	if (!(PINB & (1 << PINB0))) {
		PORTB ^= (1<<PORTB3); // toggle output 3 on
	} else {
	}
}

// timer always running, tied to B0, so when you turn on interrupt setting it to look for rising edge, always on background checking
// for rising edge
int main(void) {
	Initialize();
	while(1);
}