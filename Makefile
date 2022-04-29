
NAME = main

CC = avr-gcc
AS = avr-as
CFLAGS = -Os -mmcu=atmega328p

all: $(NAME).hex

main.o: main.c

waitloop.o: waitloop.S

$(NAME).elf: main.o waitloop.o
	$(CC) $(CFLAGS) $^ -o $@

$(NAME).hex: $(NAME).elf
	avr-objcopy -O ihex $< $@

clean:
	-rm *.o
	-rm *.elf
	-rm *.hex

write:
	avrpi -w main.hex
