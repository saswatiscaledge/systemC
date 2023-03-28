#include <systemc.h>

SC_MODULE(halfadder_tb) {
    sc_out<bool> a, b;
    sc_in<bool> sum, carry;

    void test();

    SC_CTOR(halfadder_tb) {
        SC_THREAD(test);
    }
};
