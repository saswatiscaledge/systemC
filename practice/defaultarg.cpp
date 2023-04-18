#include "systemc.h"

//function sum
int sum (int x=10,int y=20)
{ 
  return x = x+y;
}

int sc_main (int argc, char* argv[]) {
  int z;
  
  //function takes defalut values for arguments
  z=sum();
  cout <<"Value of z="<<z<<endl; 
  
  //function takes default value for second argument
  z=sum(20);
  cout <<"Value of z="<<z<<endl; 

  // Terminate simulation
  return 0;
}
