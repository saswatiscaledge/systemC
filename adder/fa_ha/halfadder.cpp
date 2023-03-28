#include <systemc.h>
#include "halfadder.h"
        
    void halfadder::add() {
    sum.write(a.read() ^ b.read());
    carry.write(a.read() & b.read());
    }

   
