#include <systemc.h>
#include "fa_ha.h"

int sc_main(int argc, char* argv[]) {
    // Create signals for the inputs and outputs of the full adder
    sc_signal<bool> a, b, cin, sum, carry;

    // Instantiate the full adder and connect its inputs and outputs
    fa_ha fa_ha("fa_ha");
    fa_ha.a(a);
    fa_ha.b(b);
    fa_ha.cin(cin);
    fa_ha.sum(sum);
    fa_ha.carry(carry);

    // Print the input and output signals
    sc_trace_file *wf = sc_create_vcd_trace_file("fa_ha_waveform");
    sc_trace(wf, a, "a");
    sc_trace(wf, b, "b");
    sc_trace(wf, cin, "cin");
    sc_trace(wf, sum, "sum");
    sc_trace(wf, carry, "carry");

    // Stimulate the inputs of the full adder
    for (int i = 0; i < 8; i++) {
        a = i & 1;
        b = (i >> 1) & 1;
        cin = (i >> 2) & 1;

        // Wait for a delta cycle before evaluating the full adder
        sc_start(1, SC_NS);

        // Print the inputs and outputs of the full adder
        cout << "a = " << a << ", b = " << b << ", cin = " << cin
             << " => sum = " << sum << ", carry = " << carry << endl;
    }

    // Close the trace file
    sc_close_vcd_trace_file(wf);

    return 0;
}

