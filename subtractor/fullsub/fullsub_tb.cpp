#include <systemc.h>
#include "fullsub.cpp"

SC_MODULE(fullsub_tb) {
	sc_out<bool> a, b, c;
	sc_in<bool> diff, borrow;
	sc_trace_file* tf;
	void test() {
		srand(time(NULL));
		for(int i = 0; i < 10; i++) {
			a.write(rand() % 2);
			b.write(rand() % 2);
			c.write(rand() % 2);
			wait(1,SC_NS);
			cout << "a:" << a.read() << ", b:" << b.read() <<  ", c:" << c.read() << ", diff:" << diff.read() << ", borrow:" << borrow.read() << endl;
		}
		sc_stop();
	}

	SC_CTOR(fullsub_tb) {
		tf = sc_create_vcd_trace_file("fullsub_waveform");
		sc_trace(tf, a, "a");
		sc_trace(tf, b, "b");
		sc_trace(tf, c, "c");
		sc_trace(tf, diff, "diff");
		sc_trace(tf, borrow, "borrow");
		SC_THREAD(test);
		sensitive << diff << borrow;
	}
	~fullsub_tb()
	{
		sc_close_vcd_trace_file(tf);
	}
};

int sc_main(int argc, char* argv[]) {
	fullsub fs("fs");
	fullsub_tb tb("tb");
	sc_signal<bool> a, b, c, diff, borrow;
	fs.a(a);
	fs.b(b);
	fs.c(c);
	fs.diff(diff);
	fs.borrow(borrow);
	tb.a(a);
	tb.b(b);
	tb.c(c);
	tb.diff(diff);
	tb.borrow(borrow);
	sc_start();
	return 0;
}

