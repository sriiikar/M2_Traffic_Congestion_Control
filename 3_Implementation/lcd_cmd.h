#include <avr/io.h>
#include <util/delay.h>

#define rs_high() PORTD |= (1 << 2);
#define rs_low() PORTD &= ~(1 << 2);

#define en_high() PORTD |= (1 << 3);
#define en_low() PORTD &= ~(1 << 3);

#define lcdport PORTB

// function to write command on LCD
void lcd_cmd(unsigned char cmd)
{
	lcdport = cmd;
	rs_low();		// rs = 0 to select the command register
	en_high();
	_delay_ms(1);
	en_low();
}