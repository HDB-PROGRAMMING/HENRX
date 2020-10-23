#ifndef HENRX_OS_H
#define HENRX_OS_H

#include "cmds.h"

String init();
String loop();

void __kernel_init() {
	String initial_msg = init();
	String loop_msg    = "";

	if (strlen(initial_msg) >= 1) {
		puts(initial_msg);
		return;
	}

	LOOP {
		loop_msg = loop();

		if (strlen(loop_msg) >= 1) {
			puts(loop_msg);
			return;
		}
	}
}

#endif
//HENRX OS header