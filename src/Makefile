CC_PREFIX?=
CC=$(CC_PREFIX)cc
AS=$(CC_PREFIX)as
AR=$(CC_PREFIX)ar

export CC_PREFIX
export CC
export AS
export AR

ARCH?=x86_64

CFLAGS+=-I$(shell pwd)/include -I$(shell pwd)/arch/$(ARCH) -ffreestanding -O2 -Wall -Wextra -std=gnu99

export ARCH
export CFLAGS


.PHONY: build kernel boot lib
all: build
	$(CC) -T linker.ld -o modix.bin -ffreestanding -O2 -nostdlib \
		arch/$(ARCH)/build/*.o \
		kernel/build/*.o \
		lib/build/*.o

build: kernel boot lib

boot:
	cd arch && make boot && cd ..

lib:
	mkdir -p lib/build
	cd lib && make lib && cd ..

kernel:
	mkdir -p kernel/build
	cd kernel && make kernel && cd ..

clean:
	- rm -r build/
	- rm -r kernel/build
	- rm -r lib/build/
	- rm -r arch/$(ARCH)/build/
	- rm modix.bin
