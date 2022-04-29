
#include <avr/io.h>

void waitloop(unsigned int n);

void msleep(int ms)
{
	int n = ms;
	for (int i = 0; i < 2000; i++) {
		waitloop(n);
	}
}

void serial_putc(char c)
{
	while (!(UCSR0A & (1 << UDRE0)));
	UDR0 = c;
}

int main()
{
	int i = 0;
	unsigned int ubrr = 31; // (freq / baud / 16 - 1) : 31250bps=31
	unsigned char data[] = "Hello, world!\r\n";
	UBRR0H = ubrr >> 8;
	UBRR0L = ubrr;

	UCSR0C = 0x06;
	UCSR0B = 1 << TXEN0;
	
	while (1) {
		serial_putc(0x90);
		serial_putc(0x30);
		serial_putc(0x7f);
		msleep(1000);
		serial_putc(0x80);
		serial_putc(0x30);
		serial_putc(0x00);
		msleep(1000);
	}
	return 0;
}

