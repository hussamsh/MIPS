#include "AND_OR.h";

const int size = 32;

SC_MODULE(AND_OR_32){

	sc_vector<sc_in<sc_logic>> A,B;
	sc_in<sc_logic> sel;

	sc_vector<sc_out<sc_logic>> Z;

	AND_OR *AR_i[size];

	SC_CTOR(AND_OR_32):
	A("A" , size),B("B" , size),Z("Z" , size)
	{
		for (int i = 0; i < size; ++i) {
			AR_i[i] = new AND_OR(gen_naming_string(i));
			(*AR_i[i])(A[i] , B[i] , sel , Z[i]);
		}
	}

	char* gen_naming_string(const int index){
		char integer_string[32];
		sprintf(integer_string, "%d", index);

		char other_string[64] = "AR";
		strcat(other_string, integer_string);

		return other_string;
	}
};
