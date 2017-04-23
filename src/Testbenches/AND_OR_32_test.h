#include "../AND_OR_32.h"

SC_MODULE(AND_OR_32_test){

	sc_vector<sc_out<sc_logic>> A,B;
	sc_out<sc_logic> sel;

	sc_vector<sc_in<sc_logic>> Z;

	SC_CTOR(AND_OR_32_test):
		A("A" , size),B("B" ,size),Z("Z", size)
	{
		SC_THREAD(process);
		for (int i = 0; i < size; ++i) {
			sensitive << A[i] << B[i];
		}
		sensitive << sel;
	}

	void process(){
		print();
		sc_trace_file *wf = sc_create_vcd_trace_file("AND_OR_test_wave");

		//Output traces
		for (int i = 0; i < size; ++i) {
			char traceName[2] = {'A', '0' + i};
			sc_trace(wf, A[i] ,traceName);
		}

		for (int i = 0; i < size; ++i) {
			char traceName[2] = {'B', '0' + i};
			sc_trace(wf, B[i] ,traceName);
		}

		sc_trace(wf, sel , "sel");

		//Input traces
		for (int i = 0; i < size; ++i) {
			char traceName[2] = {'Z', '0' + i};
			sc_trace(wf, Z[i] ,traceName);
		}


		//Test cases
		int test1A[size] = {1,1,1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1,1,1,1};
		int test1B[size] = {1,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,1,0,0,0,1,0,1,0,1,0,1,0,0,0,0,0};
		sel = SC_LOGIC_0;

		setup(test1A , test1B);wait(100, SC_NS);
		print();
		B[1] = SC_LOGIC_1;wait(100, SC_NS);
		print();
		B[2] = SC_LOGIC_1;wait(100, SC_NS);
		print();
		A[0] = SC_LOGIC_1;wait(100 , SC_NS);
		print();
		sel = SC_LOGIC_1;wait(100 , SC_NS);
		print();

		sc_stop();

		sc_close_vcd_trace_file(wf);

	}

	void setup(int arrA[], int arrB[]){

		//Pretty printing
		//This is because how the array is read and how binary is read is in reverse of each others
		reverseArray(arrA);
		reverseArray(arrB);

		for (int i = 0 ; i < size; ++i)
		{
			//Output A
			if(arrA[i] == 0){
				A[i] = SC_LOGIC_0;
			}else{
				A[i] = SC_LOGIC_1;
			}

			//Output B
			if(arrB[i] == 0){
				B[i] = SC_LOGIC_0;
			}else{
				B[i] = SC_LOGIC_1;
			}
		}
	}

	void reverseArray(int arr[]){
		int temp;
		for (int i = 0; i < size/2; ++i)
		{
			temp = arr[i];
			arr[i] = arr[size-i-1];
			arr[size-i-1] = temp;
		}
	}

	void print(){
		if(sel == SC_LOGIC_0)
			cout << "AND";
		else if(sel == SC_LOGIC_1)
			cout << "OR";

		cout << "\n";

		for (int var = size - 1; var >= 0; --var) {
			cout << Z[var];
		}
		cout << "\n";
	}
};
