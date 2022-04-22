// Define the required header files and initialse ports
#include <avr/io.h>
#include <util/delay.h>

#define rs_high() PORTD |= (1 << 2); // Define RS pin of LCD display high, connected to port D2 of atmega328
#define rs_low() PORTD &= ~(1 << 2); // Define RS pin of LCD display low, connected to port D2 of atmega328

#define en_high() PORTD |= (1 << 3); // Define EN pin of LCD display high, connected to port D3 of atmega328
#define en_low() PORTD &= ~(1 << 3); // Define EN pin of LCD display low, connected to port D3 of atmega328

#define lcdport PORTB

// Include user defined header files
#include "lcd_cmd.h" // Function to write command on LCD display
#include "lcd_data.h" // Function to write data on LCD display
#include "lcd_init.h" // Initialisng the LCD display
#include "cursorxy.h" // Setting the cursor position on the LCD display
#include "lcd_print.h" // Function to print any input value upto the desired digit on LCD display
#include "lcd_out.h" // Printing the data onto the LCD display

// Main program starts
int main(void)
{
	DDRB = 0xff; // 1111 1111
	DDRD |= (1 << 2); // Setting pin D2 of atmega 328 as output
	DDRD |= (1 << 3); // Setting pin D3 of atmega 328 as output
	
	// LANE 1
	DDRD|=(1<<PD5); // Setting pin D5 of atmega 328 as output for LEDs corresponding to Lane 1 of the traffic control system
	DDRD|=(1<<PD6); // Setting pin D6 of atmega 328 as output for LEDs corresponding to Lane 1 of the traffic control system
	DDRD|=(1<<PD7); // Setting pin D7 of atmega 328 as output for LEDs corresponding to Lane 1 of the traffic control system
	
	// LANE 2
	DDRC|=(1<<PC6); // Setting pin C6 of atmega 328 as output for LEDs corresponding to Lane 2 of the traffic control system
	DDRD|=(1<<PD0); // Setting pin D0 of atmega 328 as output for LEDs corresponding to Lane 2 of the traffic control system
	DDRD|=(1<<PD1); // Setting pin D1 of atmega 328 as output for LEDs corresponding to Lane 2 of the traffic control system
	
	// LANE 3
	DDRC|=(1<<PC5); // Setting pin C5 of atmega 328 as output for LEDs corresponding to Lane 3 of the traffic control system
	DDRC|=(1<<PC4); // Setting pin C4 of atmega 328 as output for LEDs corresponding to Lane 3 of the traffic control system
	DDRC|=(1<<PC3); // Setting pin C3 of atmega 328 as output for LEDs corresponding to Lane 3 of the traffic control system
	
	// LANE 4
	DDRC|=(1<<PC2); // Setting pin C2 of atmega 328 as output for LEDs corresponding to Lane 4 of the traffic control system
	DDRC|=(1<<PC1); // Setting pin C1 of atmega 328 as output for LEDs corresponding to Lane 4 of the traffic control system
	DDRC|=(1<<PC0); // Setting pin C0 of atmega 328 as output for LEDs corresponding to Lane 4 of the traffic control system
	
	while(1) // Infinite loop
	{
        // Initial message
        lcd_init();
		lcd_out(1,1,"MG Road Traffic"); // Display on LCD 'MG Road Traffic'
		_delay_ms(50000); // 5s delay

		// LANE 1
		lcd_init();
		lcd_out(1,1,"Lane 1 Stop"); // Display on LCD 'Lane 1 Stop'
		PORTC|=(1<<PC6); // Red LED glows
		_delay_ms(50000); // 5s delay
		PORTC&=~(1<<PC6); // Red LED stops glowing
		lcd_init();
		lcd_out(1,1,"Lane 1 Wait"); // Display on LCD 'Lane 1 Wait'
		PORTD|=(1<<PD0); // Yellow LED glows
		_delay_ms(30000); // 3s delay
		PORTD&=~(1<<PD0); // Yellow LED stops glowing
		lcd_init();
		lcd_out(1,1,"Lane 1 Go"); // Display on LCD 'Lane 1 Go'
		PORTD|=(1<<PD1); // Green LED glows
		_delay_ms(100000); // 10s delay
		PORTD&=~(1<<PD1); // Green LED stops glowing
		_delay_ms(1); // 1ms delay
		
		// LANE 2
		lcd_init();
		lcd_out(1,1,"Lane 2 Stop"); // Display on LCD 'Lane 2 Stop'
		PORTD|=(1<<PD5); // Red LED glows
		_delay_ms(50000); // 5s delay
		PORTD&=~(1<<PD5); // Red LED stops glowing
		lcd_init();
		lcd_out(1,1,"Lane 2 Wait"); // Display on LCD 'Lane 2 Wait'
		PORTD|=(1<<PD6); // Yellow LED glows
		_delay_ms(30000); // 3s delay
		PORTD&=~(1<<PD6); // Yellow LED stops glowing
		lcd_init();
		lcd_out(1,1,"Lane 2 Go"); // Display on LCD 'Lane 2 Go'
		PORTD|=(1<<PD7); // Green LED glows
		_delay_ms(100000); // 10s delay
		PORTD&=~(1<<PD7); // Green LED stops glowing
		_delay_ms(1); // 1ms delay
		
		// LANE 3
		lcd_init();
		lcd_out(1,1,"Lane 3 Stop"); // Display on LCD 'Lane 3 Stop'
		PORTC|=(1<<PC5); // Red LED glows
		_delay_ms(50000); // 5s delay
		PORTC&=~(1<<PC5); // Red LED stops glowing
		lcd_init();
		lcd_out(1,1,"Lane 3 Wait"); // Display on LCD 'Lane 3 Wait'
		PORTC|=(1<<PC4); // Yellow LED glows
		_delay_ms(30000); // 3s delay
		PORTC&=~(1<<PC4); // Yellow LED stops glowing
		lcd_init();
		lcd_out(1,1,"Lane 3 Go"); // Display on LCD 'Lane 3 Go'
		PORTC|=(1<<PC3); // Green LED glows
		_delay_ms(100000); // 10s delay
		PORTC&=~(1<<PC3); // Green LED stops glowing
		_delay_ms(1); // 1ms delay
		
		// LANE 4
		lcd_init();
		lcd_out(1,1,"Lane 4 Stop"); // Display on LCD 'Lane 4 Stop'
		PORTC|=(1<<PC2); // Red LED glows
		_delay_ms(50000); // 5s delay
		PORTC&=~(1<<PC2); // Red LED stops glowing
		lcd_init();
		lcd_out(1,1,"Lane 4 Wait"); // Display on LCD 'Lane 4 Wait'
		PORTC|=(1<<PC1); // Yellow LED glows
		_delay_ms(30000); // 3s delay
		PORTC&=~(1<<PC1); // Yellow LED stops glowing
		lcd_init();
		lcd_out(1,1,"Lane 4 Go"); // Display on LCD 'Lane 4 Go'
		PORTC|=(1<<PC0); // Green LED glows
		_delay_ms(100000); // 10s delay
		PORTC&=~(1<<PC0); // Green LED stops glowing
		_delay_ms(1); // 1ms delay
	}
}