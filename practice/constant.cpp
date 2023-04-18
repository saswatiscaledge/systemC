#include "systemc.h"
const int seconds_per_minute = 60;

int sc_main (int argc, char* argv[]) {

  cout <<"1 minute = "<< seconds_per_minute << " seconds"<<endl;
  cout <<"8 minute = "<< 8*seconds_per_minute << " seconds"<<endl;
  
  // Terminate simulation
  return 0;
}
