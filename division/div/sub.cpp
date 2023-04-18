#include <systemc.h>
//#include <const.h>

SC_MODULE(subtraction) {
	sc_in<sc_biguint<N>> a;
	sc_in<sc_biguint<N>> b;
	sc_out<sc_biguint<N>> o;

	void sub() {
		o.write(a.read() - b.read());
	}

	SC_CTOR(subtraction) {
		SC_METHOD(sub);
		sensitive << a << b;
	}
};

