#include "systemc.h"
#include "const.h"
#include "mul.cpp"
#include "sub.cpp"
#include "add.cpp"
#include "rshift.cpp"
#include "comp.cpp"

SC_MODULE(division) {
	sc_in<bool> clk;
	sc_in<bool> rst;
	sc_in<sc_biguint<1>> req;
	sc_in<sc_biguint<N>> dividend;
	sc_in<sc_biguint<N>> divisor;
	sc_out<sc_biguint<N>> Q;
	sc_out<sc_biguint<N>> R;
	sc_out<sc_biguint<1>> ready;
	sc_out<sc_biguint<1>> exception;

	sc_signal<sc_biguint<N>> D,d,Counter, RefCounter, refD, refd, Num_cycles;
	sc_signal<sc_biguint<N>> Dr, temp1, temp2, temp3;
	sc_signal<sc_biguint<1>> g,e;

	enum {START, COMPARE} s;
	void divider_func() {
		if(rst) {
			s = START;
			RefCounter = 0;
			Counter = 0;
			exception = 0;
			ready = 0;
			Num_cycles = 0;
		} else {
			if(s == START) {
				if(req == 1){
					if(divisor == 0) {
						exception = 1;
						ready = 1;
						s = START;
						Num_cycles = 1;
					} else if(divisor == 1) {
						exception = 0;
						ready = 1;
						s = START;
						Q.write(dividend.read());
						Num_cycles = 1;
					} else {
						s = COMPARE;
						refD = dividend.read();
						refd = divisor.read();
						D = dividend.read();
						d = divisor.read();
						Num_cycles = 1;
					}
				} else {
					s = START;
					ready = 0;
					Num_cycles = 0;
				}
			} else if(S == COMPARE) {
				Num_cycles = Num_cycles + 1;
				if((e == 1) || (g == 1)) {
					D = Dr;
					if(Counter == 0) {
						Counter = 1;
					} else {
						Counter = Counter << 1;
					}
				} else {
					if(Counter != 0) {
						RefCounter = temp3;
						Counter =  0;
						D = temp2;
						refD = temp2;
					} else {
						Q.write(RefCounter);
						ready = 1;
						s = START;
					}
				}
			}
		}
	}

	SC_CTOR(division) :
		dividend("div_dividend"),
		divisor("div_divisor"),
		Q("div_Q"),
		R("div_R"),
		req("div_req"),
		ready("div_ready"),
		exception("div_exception"),
		rst("div_rst"),
		clk("div_Clk")
	{
		GE* ge_i = new GE("ge_i");
		ge_i -> a(D);
		ge_i->b(d);
		ge_i->g(g);
		ge_i->e(e);
		
		SC_METHOD(divider_func);
		sensitive << clk.pos() << rst.pos();
		
		multiplication* mul_i = new multiplication("mul_i");
		mul_i->a(refd);
		mul_i->b(Counter);
		mul_i->o(temp1);
		
		subtraction* sub_i = new subtraction("sub_i");
		sub_i->a(refD);
		sub_i->b(temp1);
		sub_i->o(temp2);
		
		addition* add_i = new addition("add_i");
		add_i->a(RefCounter);
		add_i->b(Counter);
		add_i->o(temp3);
		
		rshift* rshift_i= new rshift("rshift_i");
		rshift_i->i(D);
		rshift_i->o(Dr);
    }
};













            
      	 



