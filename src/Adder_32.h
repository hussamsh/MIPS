#include "FA.h"

const int size = 32;

SC_MODULE(Adder_32){

	//Input
	sc_vector<sc_in<sc_logic>> A,B;
	sc_in<sc_logic> cin;

	//Output
	sc_vector<sc_out<sc_logic>> sum;
	sc_out<sc_logic> carry;

	//Adders
	FA *FA_i[size];
	sc_signal<sc_logic> carry_signals[size];

	SC_CTOR(Adder_32):
		A("A" , size),B("B" , size),sum("sum" , size)
		{
			for (int i = 0; i < size ; i++) {

				FA_i[i]  = new FA(gen_naming_string(i));

				if(i == 0)
					//First Full adder
					(*FA_i[i])(A[i] ,B[i] , cin , sum[i] , carry_signals[i]);
				else if(i != size-1)
					//Middle full adders
					(*FA_i[i])(A[i] ,B[i] , carry_signals[i-1] , sum[i] , carry_signals[i]);
				else
					//Last full adder
					(*FA_i[i])(A[i] ,B[i] , carry_signals[i-1] , sum[i] , carry);


				sensitive << carry_signals[i];
			}
//			dont_initialize();
		}

	char* gen_naming_string(const int index) {
		char integer_string[32];
		sprintf(integer_string, "%d", index);

		char other_string[64] = "FA";
		strcat(other_string, integer_string);

		return other_string;
	}
};


