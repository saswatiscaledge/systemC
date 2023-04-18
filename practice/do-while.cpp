#include "systemc.h"
int sc_main (int argc, char* argv[]) {
  //declaration and initialization
  int a = 9;
  int b = 10;

  //while-loop
  do{
    cout <<" a is greater than b a = "<<a<<" b = "<<b<<endl;
    a--;
  }while( a > b );

  cout <<" b is greater than a "<<endl;
    
  // Terminate simulation
  return 0;
}
