#include "systemc.h"

//function add, to add two integer numbers
int add (int a,int b)
{
 return a+b; 
}

int sc_main (int argc, char* argv[]) {
  //declaration
  int x,y,z;
  
  //initialization
  x=10;
  y=20;
  
  //function call in expression
  z = 10+ add(x,y) +20;
  cout<<"Value of z = "<<z<<endl;
  return 0;
}

