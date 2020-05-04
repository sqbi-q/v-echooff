module echo

#flag -I @VROOT
#flag @VROOT/echo.o
#include "echo.h"

fn C.displayInput(d bool)

pub fn display_input(display bool) {
	C.displayInput(display)
}