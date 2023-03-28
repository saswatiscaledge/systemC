#include <systemc.h>
#include "halfadder.cpp"

SC_MODULE(fa_ha) {
  sc_in<bool> a, b, cin;
  sc_out<bool> sum, carry;

  halfadder ha1, ha2;

  SC_CTOR(fa_ha): ha1("ha1"), ha2("ha2") {
    // Connect the first half adder
    ha1.a(a);
    ha1.b(b);
    ha1.sum(sum);
    ha1.carry(carry);

    // Connect the second half adder
    ha2.a(sum);
    ha2.b(cin);
    ha2.sum(sum);
    ha2.carry(carry);
  }
};

