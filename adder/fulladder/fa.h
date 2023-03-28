#include <systemc.h>

SC_MODULE(fa) {
    sc_in<bool> a, b,c;
    sc_out<bool> sum, carry;

    void add();
        

    SC_CTOR(fa) {
	    SC_METHOD(add);
	    sensitive << a << b << c;
    }
};

