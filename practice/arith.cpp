#include "systemc.h"
int sc_main (int argc, char* argv[]) {
  /*int a = 10;
  int b = 20;
  
  //+= operator, Arithmetic and bitwise assignment
  a += b;*/

  int a = 1;
  int b = 0;
  
  //&= operator, Arithmetic and bitwise assignment
  a &= b; 

  cout <<"Value of a = " << a << endl;
  return 0;// Terminate simulation
}
