#include "AND_OR.h"

void AND_OR::proc(){
	//sel is not a boolean, can't use bitwise operation on it , ~ and ! won't work
	out = (A & B & (sel == SC_LOGIC_0 ? SC_LOGIC_1 : SC_LOGIC_0)) | ((A | B) & sel);
}
