#include <avr/io.h>
#include <util/delay.h>

#define rs_high() PORTD |= (1 << 2);
#define rs_low() PORTD &= ~(1 << 2);

#define en_high() PORTD |= (1 << 3);
#define en_low() PORTD &= ~(1 << 3);

#define lcdport PORTB

// function to write data on LCD
void lcd_data(unsigned char dat)
{
	lcdport = dat;
	rs_high();		// rs = 0 to select the command register
	en_high();
	_delay_ms(1);
	en_low();
}