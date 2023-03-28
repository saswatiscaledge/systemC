#include <systemc.h>

SC_MODULE(fullsub) {
	sc_in<bool> a, b, c;
	sc_out<bool> diff, borrow;

	SC_CTOR(fullsub) {
		SC_METHOD(sub);
		sensitive << a << b << c;
	}
	//void halfsub::sub();//if i write .h file
	void sub() {
		diff.write(a.read() ^ b.read() ^ c.read());
		borrow.write(c.read() && (!(a.read() ^ b.read())) || ((!a.read()) & b.read()));
	}

};
