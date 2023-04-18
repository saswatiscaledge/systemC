#include <systemc.h>
//#include <const.h>

SC_MODULE(addition) {
	sc_in<sc_biguint<N>> a;
	sc_in<sc_biguint<N>> b;
	sc_out<sc_biguint<N>> o;

	void add() {
		o.write(a.read() + b.read());
	}

	SC_CTOR(addition) {
		SC_METHOD(add);
		sensitive << a << b;
	}
};

