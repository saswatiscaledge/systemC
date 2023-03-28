#include "systemc.h"
#include "and.cpp"
SC_MODULE(testbench) {
	sc_signal<sc_int<2>> a, b;
	sc_signal<sc_int<2>> f;
	sc_trace_file *pTracefile;
	
	void test() {
		for(int i=0; i<10 ;i++) {
			a.write(rand()%2);
			b.write(rand()%2);
			cout<< " a =  " << a.read() <<  " , b = "<< b.read() << " ,f = "<< f.read() << endl;
			wait(1, SC_NS);
		}
	}
	SC_CTOR(testbench) {
		pTracefile = sc_create_vcd_trace_file("and_vcd");
		sc_trace(pTracefile, a, "trace_a");
		sc_trace(pTracefile, b, "trace_b");
		sc_trace(pTracefile, f, "trace_f");
		SC_THREAD(test);
	}
	~testbench()
	{
		sc_close_vcd_trace_file(pTracefile);
	}
};

int sc_main(int argc, char* argv[]) {
	and2 and_gate("and_gate");
	testbench tb("tb");
	//tb.a(and_gate.a);
	and_gate.a(tb.a);
	and_gate.b(tb.b);
        //tb.f(and_gate.f);
	and_gate.f(tb.f);
	
	sc_start(100, SC_NS);
	sc_stop();
	return 0;
}
