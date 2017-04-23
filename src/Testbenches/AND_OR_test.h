#include "../AND_OR.h"

SC_MODULE(AND_OR_test){

	sc_out<sc_logic> a,b,sel;
	sc_in<sc_logic> out;

	SC_CTOR(AND_OR_test){
		SC_THREAD(process);
		sensitive << a << b << sel;
	}

	void process(){
		sc_trace_file *wf = sc_create_vcd_trace_file("AND_OR_test_wave");
		sc_trace(wf, a , "A");
		sc_trace(wf, b , "B");
		sc_trace(wf, sel , "sel");
		sc_trace(wf, out , "out");

		a = SC_LOGIC_0;b = SC_LOGIC_1;sel = SC_LOGIC_0;wait(100,SC_NS);
		print();
		a = SC_LOGIC_0;b = SC_LOGIC_1;sel = SC_LOGIC_1;wait(100,SC_NS);
		print();
		a = SC_LOGIC_1;b = SC_LOGIC_0;sel = SC_LOGIC_1;wait(100,SC_NS);
		print();
		a = SC_LOGIC_1;b = SC_LOGIC_0;sel = SC_LOGIC_0;wait(100,SC_NS);
		print();
		sc_stop();

		sc_close_vcd_trace_file(wf);
	}

	void print(){
		cout << "Input <A,B,sel> :: " << "<" << a.read() << b.read() << sel.read() << ">";
		cout << " | Output :: " << "<" << out.read() << ">\n";
	}
};
