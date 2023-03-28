#include <systemc.h>
#include "halfadder.h"

SC_MODULE(fa_ha) {
    sc_in<bool> a, b, cin;
    sc_out<bool> sum, carry;

    halfadder ha1, ha2;

    SC_CTOR(fa_ha) : ha1("ha1"), ha2("ha2") {
        // Connect the inputs and outputs of the half adders
        ha1.a(a);
        ha1.b(b);
        ha1.sum(sum1);
        ha1.carry(carry1);

        ha2.a(sum1);
        ha2.b(cin);
        ha2.sum(sum);
        ha2.carry(carry);
    }

     private:
        sc_signal<bool> sum1, carry1;
};

