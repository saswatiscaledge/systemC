#include<systemc.h>
//#include "const.h"

SC_MODULE(multiplication) {
	sc_in<sc_biguint<N>> a;
	sc_in<sc_biguint<N>> b;
	sc_out<sc_biguint<N>> o;

	void mul() {
		o.write(a.read() * b.read());
	}

	SC_CTOR(multiplication) {
		SC_METHOD(mul);
		sensitive << a << b;
	}
};



