#include "mul.cpp"
//#include "const.h"

SC_MODULE(mul_test){

	sc_signal<sc_uint<N>> a, b;
	sc_signal<sc_uint<N+N>> out;
	sc_signal<bool> rst;
	sc_clock clk;
	

	mul mul1;

	sc_trace_file *pTracefile;

	void stimulus();

	SC_CTOR(mul_test):
		clk("test_clk", tp),
		a("test_a"),
		b("test_b"),
		rst("test_reset"),
		out("test_out"),
		mul1("mul1")
	{
		mul1.a(a);
		mul1.b(b);
		mul1.out(out);
		mul1.rst(rst);
		mul1.clk(clk);

		pTracefile = sc_create_vcd_trace_file("multiplier_vcd_waves");

		sc_trace(pTracefile, rst, "reset");
		sc_trace(pTracefile, clk, "clk");
		sc_trace(pTracefile, a, "input_a");
                sc_trace(pTracefile, b, "input_b");
                sc_trace(pTracefile, out, "out");
                


		SC_THREAD(stimulus)
	}

	~mul_test(){
		sc_close_vcd_trace_file(pTracefile);
	}  
};


void mul_test::stimulus(){

	//wait(tp/2);
	
	srand(time(NULL));
	while(true){
		rst.write(rand()%2);
		a.write(rand() );
		b.write(rand());
		
		
 
		cout << " reset= " << rst.read() << " input_a = " << a.read() << " input_b = " << b.read() << " mul = " << out.read() << endl;
		wait(tp);
	}
}


int sc_main(int agrc, char* argv[]){
	mul_test test("mul_test");
	sc_start(15*tp);
	sc_stop();
	return 0;
}
