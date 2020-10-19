#ifndef HENRX_KERNEL_H
#define HENRX_KERNEL_H

#define VGA_ADDRESS 0xB8000
#define BUFSIZE     2200

#define NULL        0
//HENRX consts

#include "types.h"

Ui16* vga_buffer;

#include "vga.h"
#include "io.h"
//HENRX kernel modules

enum vga_color {
    BLACK,
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    GREY,
    DARK_GREY,
    BRIGHT_BLUE,
    BRIGHT_GREEN,
    BRIGHT_CYAN,
    BRIGHT_RED,
    BRIGHT_MAGENTA,
    YELLOW,
    WHITE,
};

#endif
// ginger kernel header