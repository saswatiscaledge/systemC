#include "systemc.h"
#include <iostream>
using namespace std;

int sc_main (int argc, char* argv[]) {
  //declaration and initialization
  int a = 15;
  int b = 10;
  
  my_lable://lable name  
  cout <<" @ my_label "<<endl;

  if( a > b ) {
    cout <<" a is greater than b a = "<<a<<" b = "<<b<<endl;
    a--;
    goto my_lable;
  }
  else
    cout <<" b is greater than a "<<endl;
    
    return 0;
}
