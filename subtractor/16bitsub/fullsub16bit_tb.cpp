#include <systemc.h>
#include "fullsub16bit.cpp"

SC_MODULE(fullsub16bit_tb) {
	sc_signal<sc_bv<4>> a, b,c, diff; 
	sc_signal<sc_bv<1>> borrow;

/*	sborrow<sc_bv<16>> a;
	sborrow<sc_bv<16>> b;
	sborrow<sc_bv<1>> cin;
	sc_in<sc_bv<16>> diff;
	sc_in<sc_bv<1>> borrow;*/
	sc_trace_file* tf;


	void test() {
		srand(time(NULL));
		for(int i = 0; i < 4; i++) {
			a.write(rand() % (1<<4));
			b.write(rand() % (1<<4));
			c.write(rand() % (1<<4));
			wait(1, SC_NS);
			//cout << "a:" << a.read() << ", b:" << b.read() << ", diff:" << diff.read()  <<endl;

			cout << "a:" << a.read() << ", b:" << b.read() << ", c:" << c.read() << ", diff:" << diff.read() << ", borrow:" << borrow.read() <<endl;
		}
		}
SC_CTOR(fullsub16bit_tb) {
	//sc_trace_file *tf;
	tf = sc_create_vcd_trace_file("fullsub_waveform");
	sc_trace(tf,a,"a");
	sc_trace(tf,b,"b");
	sc_trace(tf,c,"c");
	sc_trace(tf,diff,"diff");
	sc_trace(tf,borrow,"borrow");
	SC_THREAD(test);
	sensitive << diff << borrow;
}
~fullsub16bit_tb() {
	sc_close_vcd_trace_file(tf);
}
};
int sc_main(int argc, char* argv[]) {
	//sc_signal<sc_bv<16>> a, b, cin, diff; 
	//sc_signal<sc_bv<1>> borrow;
        fullsub4bit fs("fs");
	fullsub16bit_tb tb("tb");
	fs.a(tb.a);
	fs.b(tb.b);
	fs.c(tb.c);
	fs.diff(tb.diff);
	fs.borrow(tb.borrow);
	/*tb.a(a);
	tb.b(b);
	tb.cin(cin);
	tb.diff(diff);
	tb.borrow(borrow);*/
	sc_start();
	return 0;
	sc_stop();

}


