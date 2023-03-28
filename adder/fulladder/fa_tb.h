#include <systemc.h>

SC_MODULE(fa_tb) {
    sc_out<bool> a, b, c;
    sc_in<bool> sum, carry;

    void test();

    SC_CTOR(fa_tb) {
        SC_THREAD(test);
    }
};
