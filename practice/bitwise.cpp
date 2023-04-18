#include "systemc.h"
int sc_main (int argc, char* argv[]) {
  int a = 101;
  int b = 11;
  int c,d,e;
  
  //bitwise AND operator,
  c = a & b;
  d = a | b;
  e = a ^ b;
  
  cout <<"Value of c = " << c << endl;
  cout <<"Value of d = " << d << endl;
  cout <<"Value of e = " << e << endl;

  return 0;// Terminate simulation
}
