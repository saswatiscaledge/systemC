#include "systemc.h"

//function add, to add two integer numbers
void display (int a,int b)
{
 cout <<" recived a = "<<a<<" b = "<<b<<endl; 
}

int sc_main (int argc, char* argv[]) {
  
  //function calling
  display(10,20);
    
  // Terminate simulation
  return 0;
}
