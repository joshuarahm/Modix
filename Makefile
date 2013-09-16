export CC_PREFIX=x86_64-pc-elf-

all:
	cd src && make && cd .. && \
	ln -f src/modix.bin build/isodir/boot/modix && \
	grub-mkrescue -o modix.iso build/isodir

clean:
	cd src && make clean && cd ..
