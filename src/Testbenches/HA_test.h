#include "systemc.h"
#include "iostream"

SC_MODULE(HA_test){

	sc_out<sc_logic> a,b;
	sc_in<sc_logic> s,c;

	SC_CTOR(HA_test){
		SC_THREAD(process);
		sensitive << a << b;
	}


	void process(){
		print();
		sc_trace_file *wf = sc_create_vcd_trace_file("HA_test_wave");
		sc_trace(wf, a , "A");
		sc_trace(wf, b , "B");
		sc_trace(wf, s , "Sum");
		sc_trace(wf, c , "Carry");

		a = SC_LOGIC_0;b = SC_LOGIC_0;wait(100 , SC_NS);
		print();
		a = SC_LOGIC_1;b = SC_LOGIC_0;wait(100 , SC_NS);
		print();
		a = SC_LOGIC_0;b = SC_LOGIC_1;wait(100 , SC_NS);
		print();
		a = SC_LOGIC_1;b = SC_LOGIC_1;wait(100 , SC_NS);
		print();

		sc_stop();

		sc_close_vcd_trace_file(wf);

	}

	void print(){
		cout << "Input <A,B> :: " << "<" << a.read() << b.read() << ">";
		cout << " | Output <S,C> :: " << "<" << s.read() << c.read() << ">\n";
	}
};
