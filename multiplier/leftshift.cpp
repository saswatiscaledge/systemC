#include "systemc.h"
//#include "const.h"
SC_MODULE(leftshift) {
	sc_in<sc_uint<16>> a;
	sc_out<sc_uint<16>> o;
	//sc_in<bool> clk,reset;

	void process() {
		o.write(a.read()<<1);
	}

	SC_CTOR(leftshift) {
		SC_THREAD(process);
		sensitive << a;
	}
};
