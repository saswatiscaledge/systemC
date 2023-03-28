#include <systemc.h>
#include "halfadder.h"

int sc_main(int argc, char *argv[]) {
    sc_signal<bool> a, b, sum, carry;

    halfadder ha("ha");
    ha.a(a);
    ha.b(b);
    ha.sum(sum);
    ha.carry(carry);

    sc_trace_file *tf = sc_create_vcd_trace_file("half_adder_newwave");
    tf->set_time_unit(1, SC_NS);
    sc_trace(tf, a, "a");
    sc_trace(tf, b, "b");
    sc_trace(tf, sum, "sum");
    sc_trace(tf, carry, "carry");

    a = 0;
    b = 0;
    sc_start(1, SC_NS);
    assert(sum == 0);
    assert(carry == 0);

    a = 0;
    b = 1;
    sc_start(1, SC_NS);
    assert(sum == 1);
    assert(carry == 0);

    a = 1;
    b = 0;
    sc_start(1, SC_NS);
    assert(sum == 1);
    assert(carry == 0);

    a = 1;
    b = 1;
    sc_start(1, SC_NS);
    assert(sum == 0);
    assert(carry == 1);

    sc_close_vcd_trace_file(tf);

    return 0;
}

