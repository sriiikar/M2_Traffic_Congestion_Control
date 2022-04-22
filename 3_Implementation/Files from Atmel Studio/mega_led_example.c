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

// function to write data on LCD
void lcd_data(unsigned char dat)
{
	lcdport = dat;
	rs_high();		// rs = 0 to select the command register
	en_high();
	_delay_ms(1);
	en_low();
}

void lcd_init()
{
	lcd_cmd(0x38); _delay_ms(5);
	lcd_cmd(0x02); _delay_ms(5);
	lcd_cmd(0x01); _delay_ms(5);
	lcd_cmd(0x0C); _delay_ms(5);
	lcd_cmd(0x06); _delay_ms(5);
	lcd_cmd(0x80); _delay_ms(5);
}

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

//function to print any input value upto the desired digit on lcd
void lcd_print(char row, char coloumn, unsigned int value, int digits)
{
	unsigned int temp;
	unsigned int unit;
	unsigned int tens;
	unsigned int hundred;
	unsigned int thousand;
	unsigned int million;
	
	unsigned char flag=0;
	
	
	if(row==0||coloumn==0)
	{
		cursorxy(1,1);
	}
	else
	{
		cursorxy(row,coloumn);
	}
	if(digits==5 || flag==1)
	{
		million=value/10000+48;
		lcd_data(million);
		flag=1;
	}
	if(digits==4 || flag==1)
	{
		temp = value/1000;
		thousand = temp%10 + 48;
		lcd_data(thousand);
		flag=1;
	}
	if(digits==3 || flag==1)
	{
		temp = value/100;
		hundred = temp%10 + 48;
		lcd_data(hundred);
		flag=1;
	}
	if(digits==2 || flag==1)
	{
		temp = value/10;
		tens = temp%10 + 48;
		lcd_data(tens);
		flag=1;
	}
	if(digits==1 || flag==1)
	{
		unit = value%10 + 48;
		lcd_data(unit);
	}
	if(digits>5)
	{
		lcd_data('e');
	}
}

void lcd_out(char x, char y, char *str)
{
	cursorxy(x,y);
	while(*str)
	{
		lcd_data(*str);
		str++;
	}

}

int main(void)
{
	DDRB = 0xff; // 1111 1111
	DDRD |= (1 << 2);
	DDRD |= (1 << 3);
	
	// LANE 1
	DDRD|=(1<<PD5);
	DDRD|=(1<<PD6);
	DDRD|=(1<<PD7);
	
	// LANE 2
	DDRC|=(1<<PC6);
	DDRD|=(1<<PD0);
	DDRD|=(1<<PD1);
	
	// LANE 3
	DDRC|=(1<<PC5);
	DDRC|=(1<<PC4);
	DDRC|=(1<<PC3);
	
	// LANE 4
	DDRC|=(1<<PC2);
	DDRC|=(1<<PC1);
	DDRC|=(1<<PC0);
	
	while(1)
	{
		lcd_init();
		lcd_out(1,1,"MG Road Traffic");
		_delay_ms(50000);
		
		// LANE 1
		lcd_init();
		lcd_out(1,1,"Lane 1 Stop");
		PORTC|=(1<<PC6);
		_delay_ms(50000);
		PORTC&=~(1<<PC6);
		lcd_init();
		lcd_out(1,1,"Lane 1 Wait");
		PORTD|=(1<<PD0);
		_delay_ms(30000);
		PORTD&=~(1<<PD0);
		lcd_init();
		lcd_out(1,1,"Lane 1 Go");
		PORTD|=(1<<PD1);
		_delay_ms(100000);
		PORTD&=~(1<<PD1);
		_delay_ms(1);
		
		// LANE 2
		lcd_init();
		lcd_out(1,1,"Lane 2 Stop");
		PORTD|=(1<<PD5);
		_delay_ms(50000);
		PORTD&=~(1<<PD5);
		lcd_init();
		lcd_out(1,1,"Lane 2 Wait");
		PORTD|=(1<<PD6);
		_delay_ms(30000);
		PORTD&=~(1<<PD6);
		lcd_init();
		lcd_out(1,1,"Lane 2 Go");
		PORTD|=(1<<PD7);
		_delay_ms(100000);
		PORTD&=~(1<<PD7);
		_delay_ms(1);
		
		// LANE 3
		lcd_init();
		lcd_out(1,1,"Lane 3 Stop");
		PORTC|=(1<<PC5);
		_delay_ms(50000);
		PORTC&=~(1<<PC5);
		lcd_init();
		lcd_out(1,1,"Lane 3 Wait");
		PORTC|=(1<<PC4);
		_delay_ms(30000);
		PORTC&=~(1<<PC4);
		lcd_init();
		lcd_out(1,1,"Lane 3 Go");
		PORTC|=(1<<PC3);
		_delay_ms(100000);
		PORTC&=~(1<<PC3);
		_delay_ms(1);
		
		// LANE 4
		lcd_init();
		lcd_out(1,1,"Lane 4 Stop");
		PORTC|=(1<<PC2);
		_delay_ms(50000);
		PORTC&=~(1<<PC2);
		lcd_init();
		lcd_out(1,1,"Lane 4 Wait");
		PORTC|=(1<<PC1);
		_delay_ms(30000);
		PORTC&=~(1<<PC1);
		lcd_init();
		lcd_out(1,1,"Lane 4 Go");
		PORTC|=(1<<PC0);
		_delay_ms(100000);
		PORTC&=~(1<<PC0);
		_delay_ms(1);
	}
}
