#include "Testbenches/AND_OR_32_test.h"

int sc_main(int argc , char* argv[]){



	sc_start();

	return 0;
}







//AND_OR_32 tests
//sc_vector<sc_signal<sc_logic> > A_sig,B_sig,Z_sig;
//	sc_signal<sc_logic> sel;
//
//	A_sig.init(size);
//	B_sig.init(size);
//	Z_sig.init(size);
//
//	AND_OR_32 adder("AR");
//	adder.A.bind(A_sig);
//	adder.B.bind(B_sig);
//	adder.sel.bind(sel);
//	adder.Z.bind(Z_sig);
//
//	AND_OR_32_test test("test1");
//	test.A.bind(A_sig);
//	test.B.bind(B_sig);
//	test.sel.bind(sel);
//	test.Z.bind(Z_sig);

//Adder_32 tests


//sc_vector<sc_signal<sc_logic> > A_sig,B_sig,sum_sig;
//	sc_signal<sc_logic> cin,carry;
//A_sig.init(size);
//	B_sig.init(size);
//	sum_sig.init(size);
//
//	Adder_32 adder("adder");
//	adder.A.bind(A_sig);
//	adder.B.bind(B_sig);
//	adder.cin.bind(cin);
//	adder.sum.bind(sum_sig);
//	adder.carry.bind(carry);
//
//	Adder_32_test test("test1");
//	test.A.bind(A_sig);
//	test.B.bind(B_sig);
//	test.cin.bind(cin);
//	test.sum.bind(sum_sig);
//	test.carry.bind(carry);










//	sc_signal<sc_logic> A_sig, B_sig , cin_sig , s_sig , cout_sig;

//	FA FA1("FA1");
//	FA1(A_sig , B_sig , cin_sig , s_sig , cout_sig);
//
//	A_sig = SC_LOGIC_1;
//	B_sig = SC_LOGIC_1;
//	cin_sig = SC_LOGIC_1;
//
//	sc_start(100 , SC_NS);
//	cout << "Sum is : " << s_sig << " carry is : " << cout_sig << "\n";


//	sc_start();
