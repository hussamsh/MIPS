#include "systemc.h"

SC_MODULE(AND_OR){

	// sel=0 -> AND
	// sel=1 -> OR

	sc_in<sc_logic> A,B,sel;
	sc_out<sc_logic> out;

	void proc();

	SC_CTOR(AND_OR){
		SC_METHOD(proc);
		sensitive << A << B << sel;
	}
};
