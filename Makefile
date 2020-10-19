output:
	@as --32 src/boot/boot.S -o bin/boot.o
	@gcc -m32 -c src/HENRX.C -o bin/HENRX.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
	@ld -m elf_i386 -T src/linker.ld bin/HENRX.o bin/boot.o -o bin/HENRX.bin -nostdlib
	@grub-file --is-x86-multiboot HENRX.bin
	@mkdir -p bin/boot/grub
	@cp bin/HENRX.bin bin/boot/HENRX.bin
	@cp src/boot/grub.cfg bin/boot/grub/grub.cfg

run:
	qemu-system-x86_64 -cdrom bin/ginger.iso

ISO:
	@grub-mkrescue -o bin/HENRX.iso bin