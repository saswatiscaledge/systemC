#include <systemc.h>
#include "division.cpp"

SC_MODULE(div_tb) {
    sc_clock clk;
    sc_signal<bool> rst;
    sc_signal<sc_biguint<N>> dividend;
    sc_signal<sc_biguint<N>> divisor;
    sc_signal<sc_biguint<1>> req;
    sc_signal<sc_biguint<N>> Q;
    sc_signal<sc_biguint<N>> R;
    sc_signal<sc_biguint<1>> ready;
    sc_signal<sc_biguint<1>> exception;

    division* dut;
     // Open trace file
        //sc_trace_file* tf = sc_create_vcd_trace_file("trace");
	
	void run_test() {
		// Initialize signals
		dividend = 15;
		divisor = 2;
		req = 0;
		rst = 1;
		wait(1, SC_NS);
		rst = 0;
		wait(1, SC_NS);
		req = 1;
		wait(1, SC_NS);
		// Wait until the divider is done
		while (ready.read() == 0) {
			wait(1, SC_NS);
		}
		cout<< "Current simulation time: " << sc_time_stamp() << " reset =  " << rst.read()<< " dividend =  " << dividend.read() << " divisor =  " << divisor.read() << " Q =  "<< Q.read() <<" R="<< R.read()<< endl;
	}
	/* void run_test() {
	 srand (time(NULL));
        
        while (true) {
            // Initialize signals with random values
            dividend = 15;
            divisor = 5;
            req = 0;
            rst = 1;
            wait(1, SC_NS);
            rst = 0;
            wait(1, SC_NS);
            req = 1;
	    //dividend = rand();
            //divisor = rand();

             wait(1, SC_NS);
	     //req = 0;

            // Wait until the divider is done
            while (ready.read() == 0) {
                wait(1, SC_NS);
            }
            // Check the result
            //assert(Q.read() == 1);
            cout << "Current simulation time: " << sc_time_stamp() << " reset = " << rst.read() << " req = " << req.read() << "ready = " << ready.read() << " dividend = " << dividend.read() << " divisor = " << divisor.read() << " Q = " << Q.read() << " R = " << R.read() << endl;
            //wait(10, SC_NS);
	    // Dump signals to trace file
                }
 }*/
    

    SC_CTOR(div_tb)
        : clk("clk", 1, SC_NS)
    {
        dut = new division("dut");
        dut->dividend(dividend);
        dut->divisor(divisor);
        dut->Q(Q);
        dut->R(R);
        dut->req(req);
        dut->ready(ready);
        dut->exception(exception);
        dut->rst(rst);
        dut->clk(clk);

	/*sc_trace(tf, clk, "clk");
            sc_trace(tf, rst, "rst");
            sc_trace(tf, dividend, "dividend");
            sc_trace(tf, divisor, "divisor");
            sc_trace(tf, req, "req");
            sc_trace(tf, Q, "Q");
            sc_trace(tf, R, "R");
            sc_trace(tf, ready, "ready");
            sc_trace(tf, exception, "exception");*/
       

        SC_THREAD(run_test);
    }

    ~div_tb() {
        //delete dut;

        // Close trace file
      //  sc_close_vcd_trace_file(tf);

    }
};

int sc_main(int argc, char* argv[]) {
    div_tb tb("tb");
    sc_start(100,SC_NS);
    //sc_stop();
    return 0;
}

