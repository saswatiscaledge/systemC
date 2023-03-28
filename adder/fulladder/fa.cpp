#include <systemc.h>
#include "fa.h"
        
    void fa::add() {
    sum.write(a.read() ^ b.read() ^ c.read());
    carry.write(a.read() & b.read()| b.read() & c.read() | c.read() & a.read());
    }

