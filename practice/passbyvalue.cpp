#include "systemc.h"

//function sum
int sum (int x,int y)
{ 
  return x = x+y;
}

int sc_main (int argc, char* argv[]) {
  int x=20;
  int y=30;
  int z;
  
  //function call
  z=sum(x,y);
  
  //value of x,y and z
  cout <<"Value of x="<<x<<endl;  
  cout <<"Value of y="<<y<<endl; 
  cout <<"Value of z="<<z<<endl; 
  // Terminate simulation
  return 0;
}
