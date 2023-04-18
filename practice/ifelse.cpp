#include "systemc.h"
int sc_main (int argc, char* argv[]) {
  //declaration and initialization
  int a = 10;
  int b = 30;
  
  //if-else 
  if( a > b )
    cout <<" a is greater than b "<<endl;
  else
  {
    cout <<" b is greater than a "<<endl;
    if((b-a) > a)
      cout <<" b-a is greater than a"<<endl;
    else 
      cout <<" b-a is less than a "<<endl;
  }
    
  return 0;
}
