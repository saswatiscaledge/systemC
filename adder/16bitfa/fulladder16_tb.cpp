#include <systemc.h>
//#include <iostream>

#include "fulladder16.cpp"

SC_MODULE(fulladder16_tb) {
	sc_signal<sc_bv<16>> a, b, cin, sum; 
	sc_signal<sc_bv<1>> c_out;

/*	sc_out<sc_bv<16>> a;
	sc_out<sc_bv<16>> b;
	sc_out<sc_bv<1>> cin;
	sc_in<sc_bv<16>> sum;
	sc_in<sc_bv<1>> c_out;*/
	sc_trace_file* tf;


	void test() {
		srand(time(NULL));
		for(int i = 0; i < 16; i++) {
			a.write(rand() % (1<<16));
			b.write(rand() % (1<<16));
			cin.write(rand() % (1<<4));
			wait(1, SC_NS);
			cout << "a:" << a.read() << ", b:" << b.read() << ", cin:" << cin.read() << ", sum:" << sum.read() << ", c_out:" << c_out.read() <<endl;
		}
		}
SC_CTOR(fulladder16_tb) {
	//sc_trace_file *tf;
	tf = sc_create_vcd_trace_file("fulladder16_waveform");
	sc_trace(tf,a,"a");
	sc_trace(tf,b,"b");
	sc_trace(tf,cin,"cin");
	sc_trace(tf,sum,"sum");
	sc_trace(tf,c_out,"c_out");
	SC_THREAD(test);
	sensitive << sum << c_out;
}
~fulladder16_tb() {
	sc_close_vcd_trace_file(tf);
}
};
int sc_main(int argc, char* argv[]) {
	//sc_signal<sc_bv<16>> a, b, cin, sum; 
	//sc_signal<sc_bv<1>> c_out;
	fulladder16 fa("fa");
	fulladder16_tb tb("tb");
	fa.a(tb.a);
	fa.b(tb.b);
	fa.cin(tb.cin);
	fa.sum(tb.sum);
	fa.c_out(tb.c_out);
	/*tb.a(a);
	tb.b(b);
	tb.cin(cin);
	tb.sum(sum);
	tb.c_out(c_out);*/
	sc_start();
	return 0;
	sc_stop();

}


/*  sc_trace_file *tf = sc_create_vcd_trace_file("fulladder16_waveform");
  tf->set_time_unit(1, SC_NS);
  sc_trace(tf, a, "a");
  sc_trace(tf, b, "b");
  sc_trace(tf, cin, "cin");
  sc_trace(tf, sum, "sum");
  sc_trace(tf, c_out, "c_out");

  a = 0;
  b = 0;
  cin = 0;
  sc_start(1, SC_NS);

  for (int i = 0; i < 65536; i++) {
    a = i & 0xFFFF;
    b = (i >> 8) & 0xFFFF;
    cin = (i >> 16) & 0x1;
    sc_start(1, SC_NS);
    std::c_out << "a: " << a.read() << ", b: " << b.read() << ", cin: " << cin.read()
              << ", sum: " << sum.read() << ", c_out: " << c_out.read() << std::endl;
  }

  sc_close_vcd_trace_file(tf);

  return 0;
}*/

