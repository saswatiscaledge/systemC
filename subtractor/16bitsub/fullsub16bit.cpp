#include <systemc.h>

SC_MODULE(fullsub4bit) {
	sc_in<sc_bv<4>> a, b, c;
	sc_out<sc_bv<4>> diff;
	sc_out<sc_bv<1>> borrow;

	void sub() {
		sc_bv<4> a_val = a.read();
		sc_bv<4> b_val = b.read();
		sc_bv<4> c_val = c.read();

		for(int i = 0; i < 4; i++) {
			sc_logic borrow_bit = (b_val[i] & c_val[i]) | (a_val[i] & (b_val[i] ^ c_val[i]));
			borrow.write(borrow.read() | (borrow_bit.to_bool() << i));
			//borrow[i] = borrow_bit;
			sc_logic diff_bit = (a_val[i] ^ b_val[i] ^ c_val[i]);
			diff.write(diff.read() | (diff_bit.to_bool() << i));
			//diff[i] = diff_bit;
		}
	}
	SC_CTOR(fullsub4bit) {
		SC_METHOD(sub);
		sensitive << a << b << c;
	}
};
	
/*#include <systemc.h>

SC_MODULE(fullsub4bit) {
  sc_in<sc_bv<4>> a, b, c;
  sc_out<sc_bv<4>> diff;
  sc_out<sc_bv<1>> borrow;

  void sub() {
    sc_bv<4> a_val = a.read();
    sc_bv<4> b_val = b.read();
    sc_bv<4> c_val = c.read();

    sc_bv<4> diff_val = 0;
    sc_bv<4> borrow_val = 0;

    for (int i = 0; i < 4; i++) {
      sc_bit full_subtractor = (a_val[i] ^ b_val[i] ^ c_val[i]);
      diff[i] = full_subtractor;
      if (i < 15) {
        c_val[i+1] = (b_val[i] & c_val[i]) | (a_val[i] & (b_val[i] ^ c_val[i]));
      }
      else {
        borrow = (b_val[i] & c_val[i]) | (a_val[i] & (b_val[i] ^ c_val[i])) ;
      }
    }
  }
    //c.write(c_val);

    diff.write(diff_val);
    cout.write(borrow_val);
  

  SC_CTOR(fullsub4bit) {
    SC_METHOD(sub);
    sensitive << a << b << c;
  }
};*/
