#include<systemc.h>
//#include "const.h"

SC_MODULE(rshift) {
	sc_in<sc_biguint<N>> i;
	sc_out<sc_biguint<N>> o;
	void shift() {
		//o.write(i.read().range(N - 2,0),0);
		o.write((0, i.read().range(N-1, 1)));
	}
	SC_CTOR(rshift) {
		SC_METHOD(shift);
		sensitive << i;
	}
};


