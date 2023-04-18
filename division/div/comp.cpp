#include<systemc.h>
//#include "const.h"
SC_MODULE(GE) {
    sc_in< sc_biguint<N> > a;
    sc_in< sc_biguint<N> > b;
    sc_out< sc_biguint<1>> g;
    sc_out<sc_biguint<1> > e;

    void compare() {
        g.write(a.read() > b.read());
        e.write(a.read() == b.read());
    }

    SC_CTOR(GE) {
        SC_METHOD(compare);
        sensitive << a << b;
    }
}; 
