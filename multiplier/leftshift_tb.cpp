#include "systemc.h"
#include "leftshift.cpp"

int sc_main(int argc,char* argv[]) {
	sc_signal<sc_uint<16>> a;
	sc_signal<sc_uint<16>> o;

	leftshift shift("leftshift");
	shift.a(a);
	shift.o(o);

	a = 16'b1001;

	sc_start();

	cout << "after leftshift :"<< o.read() << endl;
	return 0;
}


/*SC_MODULE(leftshift_tb) {
	//sc_clock clk;
	//sc_signal<bool> reset;
	sc_signal<sc_uint<N>> a;
	sc_signal<sc_uint<N>> o;
	
	sc_trace_file *tf;
	leftshift* shift;
	
	void stimulus();
	
	SC_CTOR(leftshift_tb):
		clk("clk", 10, SC_NS) {
			// Connect the signals
			shift = new leftshift("Leftshift");
			for(int i = 0; i< N; i++) {
				shift->a[i](a[i]);
				shift->o[i](o[i]);
			}
			
			SC_THREAD(stimulus);
		}
	~leftshift_tb() {
		sc_close_vcd_trace_file(tf);
	}
};


void leftshift_tb::stimulus() {
	srand(time(NULL));
	while (true){
		cout << "start" <<endl;
		
		for(int i = N-1; i>=0;i--) {
			a[i].write(rand() % 2);
		}
	        cout <<"a =";
		for(int i = N-1; i>=0 ; i--) {
			cout << a[i];
		}
		cout << " o = ";
		for(int i = N-1; i>=0 ; i--) {
			cout << o[i];
		}
		cout << "  ";	
		cout << "end " << endl;
                wait(0.01, SC_NS);   //added this because of in the wave form i am geting started from the 00 which is not needed but when reset is 1 is taking some extra datas
		tf = sc_create_vcd_trace_file("leftshiftwaveform");

		// Add signals to trace
		sc_trace(tf, a, "a");
	       	sc_trace(tf, o, "o");
		wait(10, SC_NS);
	}
}


int sc_main(int argc, char* argv[]){
       leftshift_tb test("test");
       sc_start(100, SC_NS);
       sc_stop();
       return 0;
} */

