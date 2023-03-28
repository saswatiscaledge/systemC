#include <systemc.h>

SC_MODULE(halfadder) {
    sc_in<bool> a, b;
    sc_out<bool> sum, carry;

    void add();
        

    SC_CTOR(halfadder) {
        SC_METHOD(add);
        sensitive << a << b;
    }
};


