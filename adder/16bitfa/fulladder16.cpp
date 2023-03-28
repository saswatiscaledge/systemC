#include <systemc.h>
//#include "fulladder16.h"

SC_MODULE(fulladder16) {
  sc_in<sc_bv<16>> a, b;
  sc_in<sc_bv<16>> cin;
  sc_out<sc_bv<16>> sum;
  sc_out<sc_bv<1>> c_out;

  void add() {
    sc_bv<16> a_val;
    a_val = a.read();
    sc_bv<16> b_val;
    b_val = b.read();
    sc_bv<16> cin_val;
    cin_val = cin.read();

    sc_bv<16> sum_val;
    sum_val = sum.read();
    sc_bv<1> c_out_val;
    c_out_val = c_out.read();

    for (int i = 0; i < 16; i++) {
	    if (i == 0) {
		    sum_val[i] = a_val[i] ^ b_val[i] ^ cin_val[i];
		    c_out_val[i] =  (a_val[i] & b_val[i]) | (b_val[i] & cin_val[i]) | (a_val[i] & cin_val[i]);
	    }
	    else {
		    cin_val[i] = c_out_val[i-1];
		    sum_val[i] = a_val[i] ^ b_val[i] ^ cin_val[i];
		    c_out_val[i] =  (a_val[i] & b_val[i]) | (b_val[i] & cin_val[i]) | (a_val[i] & cin_val[i]);
	    }
      /*sc_bv<1> full_adder = (a_val[i] ^ b_val[i] ^ cin_val[i]);
      sum_val[i] = (a_val[i] ^ b_val[i] ^ cin_val[i]);
      sc_bv<1> c_out_val_bit = ((a_val[i] & b_val[i]) | (cin_val[i] & (a_val[i] ^ b_val[i])));
      c_out_val = c_out_val_bit;
      cin_val[i+1] = full_adder;*/
    }

    sum.write(sum_val);
    c_out.write(c_out_val);
  }

  SC_CTOR(fulladder16) {
    SC_METHOD(add);
    sensitive << a << b << cin;
  }
};



/*#include <systemc.h>
//#include "fulladder16.h"

SC_MODULE(fulladder16) {
  sc_in<sc_bv<16>> a, b;
  sc_in<sc_bv<16>> cin;
  sc_out<sc_bv<16>> sum;
  sc_out<sc_bv<1>> c_out;

  void add() {
    sc_bv<16> a_val;
    a_val = a.read();
    sc_bv<16> b_val;
    b_val = b.read();
    sc_bv<16> cin_val;
    cin_val = cin.read();

    sc_bv<16> sum_val;
    sum_val = sum.read();
    sc_bv<1> c_out_val;
    c_out_val = c_out.read();

    for (int i = 0; i < 16; i++) {
	    /*sum_val[i] = a_val[i] ^ b_val[i];
	    c_out_val[i] = a_val[i] & b_val[i];*/
     /* sc_bv<1> full_adder = (a_val[i] ^ b_val[i] ^ cin_val[i]);
      sum_val[i] = (a_val[i] ^ b_val[i] ^ cin_val[i]);
      c_out_val = ((a_val[i] & b_val[i]) | (cin_val[i] & (a_val[i] ^ b_val[i])));
      cin_val = full_adder;*/
      /*sum_val[i] = full_adder[0];
      if (i < 15) {
        cin_val.write(full_adder[1]);
      }
      else {
        c_out_val.write(full_adder[1]);
      }*/
     /* if (i == 0) {
	      sum_val[i] = a_val[i] ^ b_val[i];
	      c_out_val[i] =  (a_val[i] & b_val[i]) | (b_val[i] & cin_val[i]) | (a_val[i] & cin_val[i]);
      }
      else {
	      cin_val[i] = c_out_val[i-1];
	      sum_val[i] = a_val[i] ^ b_val[i] ^ cin_val[i];
	      c_out_val[i] =  (a_val[i] & b_val[i]) | (b_val[i] & cin_val[i]) | (a_val[i] & cin_val[i]);
      }*/




    /*}

    sum.write(sum_val);
    c_out.write(c_out_val);
  }

  SC_CTOR(fulladder16) {
    SC_METHOD(add);
    sensitive << a << b << cin;
  }
};*/

