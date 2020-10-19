#ifndef HENRX_IO_H
#define HENRX_IO_H

void print(char text[], Ui8 fore_color, Ui8 back_color) {
	for (int i = 0; text[i] != NULL; i++) {
		vga_buffer[i] = vga_entry(text[i], fore_color, back_color);
	}
}

#endif
//HENRX IO header