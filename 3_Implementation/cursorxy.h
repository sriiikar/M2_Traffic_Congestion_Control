#include <avr/io.h>
#include <util/delay.h>

#define rs_high() PORTD |= (1 << 2);
#define rs_low() PORTD &= ~(1 << 2);

#define en_high() PORTD |= (1 << 3);
#define en_low() PORTD &= ~(1 << 3);

#define lcdport PORTB

void cursorxy(char x, char y)
{
	if( ( x < 1 || x > 2) || (y < 1 || y > 16) )
	{
		x = 1;
		y = 1;
	}
	if(x == 1)
	lcd_cmd(0x7F+y);
	else
	lcd_cmd(0xBF+y);
}