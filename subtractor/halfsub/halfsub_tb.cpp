#include <systemc.h>
#include "halfsub.cpp"

SC_MODULE(halfsub_tb) {
	sc_out<bool> a, b;
	sc_in<bool> diff, borrow;
	sc_trace_file* tf;
	void test() {
		srand(time(NULL));
		for(int i = 0; i < 10; i++) {
			a.write(rand() % 2);
			b.write(rand() % 2);
			wait(1,SC_NS);
			cout << "a:" << a.read() << ", b:" << b.read() << ", diff:" << diff.read() << ", borrow:" << borrow.read() << endl;
		}
		sc_stop();
	}

	SC_CTOR(halfsub_tb) {
		tf = sc_create_vcd_trace_file("halfsub_waveform");
		sc_trace(tf, a, "a");
		sc_trace(tf, b, "b");
		sc_trace(tf, diff, "diff");
		sc_trace(tf, borrow, "borrow");
		SC_THREAD(test);
		sensitive << diff << borrow;
	}
	~halfsub_tb()
	{
		sc_close_vcd_trace_file(tf);
	}
};

int sc_main(int argc, char* argv[]) {
	halfsub hs("hs");
	halfsub_tb tb("tb");
	sc_signal<bool> a, b, diff, borrow;
	hs.a(a);
	hs.b(b);
	hs.diff(diff);
	hs.borrow(borrow);
	tb.a(a);
	tb.b(b);
	tb.diff(diff);
	tb.borrow(borrow);
	sc_start();
	return 0;
}


