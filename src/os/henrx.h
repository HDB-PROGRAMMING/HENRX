#ifndef HENRX_OS_H
#define HENRX_OS_H

#include "cmds.h"

void init();
void loop();

void __kernel_init() {
	init();

	while (TRUE) {
		loop();
	}
}

#endif
//HENRX OS header