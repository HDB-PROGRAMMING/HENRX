output:
	@as --32 src/boot/boot.S -o bin/boot.o
	@gcc -m32 -c src/main.c -o bin/HENRX.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
	@ld -m elf_i386 -T src/linker.ld bin/HENRX.o bin/boot.o -o bin/HENRX.bin -nostdlib
	@grub-file --is-x86-multiboot bin/HENRX.bin
	@mkdir -p bin/boot/grub
	@cp bin/HENRX.bin bin/boot/HENRX.bin
	@cp src/boot/grub.cfg bin/boot/grub/grub.cfg
	@rm bin/HENRX.o
	@rm bin/boot.o
	@rm bin/HENRX.bin

ISO:
	@grub-mkrescue -o bin/HENRX.iso bin

assembly:
	@gcc -S src/main.c -o bin/HENRX.S

bins:
	@as --32 src/boot/boot.S -o bin/boot.o
	@gcc -m32 -c src/main.c -o bin/HENRX.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
	@ld -m elf_i386 -T src/linker.ld bin/HENRX.o bin/boot.o -o bin/HENRX.bin -nostdlib

run:
	@qemu-system-x86_64 -cdrom bin/HENRX.iso