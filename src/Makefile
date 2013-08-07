CC_PREFIX?==""

CC=$(CC_PREFIX)gcc
AS=$(CC_PREFIX)as

CFLAGS=-ffreestanding -O2 -Wall -Wextra -std=gnu99

OBJS:=boot.o kernel.o util.o terminal.o

all: $(OBJS)
	$(CC) -T linker.ld -o modix.bin -ffreestanding -O2 -nostdlib $(OBJS)

boot.o: boot.s
	$(AS) boot.s -o boot.o

kernel.o: kernel.c
	$(CC) -c kernel.c -o kernel.o $(CFLAGS)

util.o: util.c
	$(CC) -c util.c -o util.o $(CFLAGS)

terminal.o: terminal.c
	$(CC) -c terminal.c -o terminal.o $(CFLAGS)

clean:
	rm -rf *.o modix.bin
