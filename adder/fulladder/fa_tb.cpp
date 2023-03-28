#include <systemc.h>
#include "fa.h"

int sc_main(int argc, char *argv[]) {
    sc_signal<bool> a, b, c, sum, carry;

    fa fa("fa");
    fa.a(a);
    fa.b(b);
    fa.c(c);
    fa.sum(sum);
    fa.carry(carry);

    sc_trace_file *tf = sc_create_vcd_trace_file("fa_wave");
    tf->set_time_unit(1, SC_NS);
    sc_trace(tf, a, "a");
    sc_trace(tf, b, "b");
    sc_trace(tf,c,"c");
    sc_trace(tf, sum, "sum");
    sc_trace(tf, carry, "carry");

    a = 0;
    b = 0;
    c = 0;
    sc_start(1, SC_NS);
    assert(sum == 0);
    assert(carry == 0);

    a = 0;
    b = 1;
    c = 0;
    sc_start(1, SC_NS);
    assert(sum == 1);
    assert(carry == 0);

    a = 1;
    b = 0;
    c = 1;
    sc_start(1, SC_NS);
    assert(sum == 0);
    assert(carry == 1);

    a = 1;
    b = 1;
    c = 1;
    sc_start(1, SC_NS);
    assert(sum == 1);
    assert(carry == 1);

    sc_close_vcd_trace_file(tf);

    return 0;
}

