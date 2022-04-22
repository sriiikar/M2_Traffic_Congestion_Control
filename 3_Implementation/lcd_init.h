#include <avr/io.h>
#include <util/delay.h>

#define rs_high() PORTD |= (1 << 2);
#define rs_low() PORTD &= ~(1 << 2);

#define en_high() PORTD |= (1 << 3);
#define en_low() PORTD &= ~(1 << 3);

#define lcdport PORTB

void lcd_init()
{
	lcd_cmd(0x38); _delay_ms(5);
	lcd_cmd(0x02); _delay_ms(5);
	lcd_cmd(0x01); _delay_ms(5);
	lcd_cmd(0x0C); _delay_ms(5);
	lcd_cmd(0x06); _delay_ms(5);
	lcd_cmd(0x80); _delay_ms(5);
}