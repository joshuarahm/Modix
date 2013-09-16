all: boot.s
	mkdir -p build
	$(AS) boot.s -o build/boot.o
	$(AR) -r build/boot.a boot.s
