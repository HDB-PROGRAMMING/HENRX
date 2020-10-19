#ifndef HENRX_VGA_H
#define HENRX_VGA_H

Ui16 vga_entry(unsigned char ch, Ui8 fore_color, Ui8 back_color) {
    Ui16 ax = 0;
    Ui8  ah = 0, al = 0;

    ah = back_color;
    ah <<= 4;
    ah |= fore_color;
    ax = ah;
    ax <<= 8;
    al = ch;
    ax |= al;

    return ax;
}

void clear_vga_buffer(Ui16** buffer, Ui8 fore_color, Ui8 back_color) {
    Ui32 i;
    for (i = 0; i < BUFSIZE; i++) {
        (*buffer)[i] = vga_entry(NULL, fore_color, back_color);
    }
}

void init_vga(Ui8 fore_color, Ui8 back_color) {
    vga_buffer = (Ui16*)VGA_ADDRESS;
    clear_vga_buffer(&vga_buffer, fore_color, back_color);
}

#endif
//HENRX vga module