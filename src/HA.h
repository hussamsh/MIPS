#include"systemc.h"

SC_MODULE(HA){
	sc_in<sc_logic> A,B;
	sc_out<sc_logic> s,c;

	void Add();

	SC_CTOR(HA){
		SC_METHOD(Add);
		sensitive << A << B;
	}
};
