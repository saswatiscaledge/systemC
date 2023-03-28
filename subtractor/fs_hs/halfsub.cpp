#include <systemc.h>

SC_MODULE(halfsub) {
	sc_in<bool> a, b;
	sc_out<bool> diff, borrow;

	SC_CTOR(halfsub) {
		SC_METHOD(sub);
		sensitive << a << b;
	}
	//void halfsub::sub();//if i write .h file
	void sub() {
		diff.write(a.read() ^ b.read());
		borrow.write((!a.read()) && b.read());
	}

};
