#include <systemc.h>
#include "halfsub.cpp"

SC_MODULE(fs_hs) {
	sc_in<bool> a, b, c;
	sc_out<bool> diff, borrow;
	halfsub hs1,hs2;
	
	
	SC_CTOR(fs_hs): hs1("hs1"), hs2("hs2") {
		// Connect the first half subtractor
		hs1.a(a);
		hs1.b(b);
		hs1.diff(diff1);
		hs1.borrow(borrow1);
		// Connect the second half subtractor
		hs2.a(diff1);
		hs2.b(c);
		hs2.diff(diff2);
		hs2.borrow(borrow2);
	}
	private:
	sc_signal<bool> diff1, borrow1, diff2, borrow2;
};
