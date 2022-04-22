#include <avr/io.h>
#include <util/delay.h>

#define rs_high() PORTD |= (1 << 2);
#define rs_low() PORTD &= ~(1 << 2);

#define en_high() PORTD |= (1 << 3);
#define en_low() PORTD &= ~(1 << 3);

#define lcdport PORTB

void lcd_out(char x, char y, char *str)
{
	cursorxy(x,y);
	while(*str)
	{
		lcd_data(*str);
		str++;
	}

}