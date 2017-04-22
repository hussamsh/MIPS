#include "HA.h"

SC_MODULE(FA){

	sc_in<sc_logic> a,b,c_in;
	sc_out<sc_logic> s,c_out;

	sc_signal<sc_logic> c1,s1,c2;

	HA HA1 , HA2;

	void proc_or();

	SC_CTOR(FA):HA1("HA1"),HA2("HA2"){
		HA1(a,b,s1,c1);
		HA2(s1,c_in,s,c2);
		SC_METHOD(proc_or);
		sensitive << c1 << c2;
	}

};
