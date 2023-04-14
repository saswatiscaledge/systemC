#include "systemc.h"
#include "const.h"
SC_MODULE(mul){
	sc_in<bool> clk;
	sc_in<bool> rst;
	sc_in<sc_uint<N>> a,b;

	sc_out<sc_uint<N+N>> out;

	void process(){
		sc_uint<N+N> temp1;
		sc_uint<N+N> temp2;
		sc_uint<N+N> temp3;
		sc_uint<N> b0 = b.read();
		sc_uint<N> a0=a.read();
		temp1=0;
		temp2=0;
		temp3=0;

		sc_uint<1> b0_value;
		b0_value=b.read()[0];
		
		/*temp1[0]=b0_value?static_cast<int>( a.read()):0;
		temp2[0]=temp1[0]<<0;
		temp3[0]=temp2[0];*/

		//full_adder* fadd[N];
		if(rst)
		{
			out.write(0);
		}
		else{
		for(int i=0;i<=N-1;i++)
		{
			//fadd[i] = new full_adder (sc_gen_unique_name("fadd"));
			

		   temp1=b0[i]?static_cast<int>(a0):0;
		   temp2=temp1<<i;
		   /*fadd[i]->a(temp3[i-1]);
		   fadd[i]->b(temp2[i]);
		   fadd[i]->sum(temp3[i]);*/
		   temp3=temp3+temp2;
		}
		out.write(temp3);
	}
	}


	   
	   SC_CTOR(mul):
		clk("clk"),
		a("a"),
		b("b"),
		rst("reset"),
		out("out")
		//mul1("mul1")

	{
		SC_METHOD(process);
		sensitive<<a<<b;
		sensitive<<clk.pos();
		sensitive<<rst.pos();
		

	}


};


/*const int N = 16; // Number of bits in input and output
const int WIDTH = 2 * N; // Total width of inputs and outputs

SC_MODULE(multiplier) {
    sc_in<sc_bv<N>> a;
    sc_in<sc_bv<N>> b;
    sc_out<sc_bv<WIDTH>> o;

    sc_bv<WIDTH> shifted_b[N]; // Signals to store shifted versions of b

    void shift() {
        for(int i = 0; i < N; i++) {
            shifted_b[i].write(b.read() << i); // Shift b left by i bits and store in shifted_b[i]
        }
    }

    void multiply() {
        sc_bv<WIDTH> temp = sc_bv<WIDTH>(0);
        for(int i = 0; i < N; i++) {
            if(a.read()[i] == 1) { // If ith bit of a is 1, add shifted_b[i] to temp
                temp = temp + shifted_b[i];
            }
        }
        o.write(temp);
    }

    SC_CTOR(multiplier) {
        SC_METHOD(shift);
        sensitive << b;

        SC_METHOD(multiply);
        sensitive << a;
    }
};*/


