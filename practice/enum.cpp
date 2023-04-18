#include <systemc.h>
#include <string>
using namespace std;

int sc_main (int argc, char* argv[]) {
  
  //string declaration and initialization
  string mystring   = "Hello world";
  string mystring_1;
  string mystring_2;
  string mystring_3;
  
  //initialization, can be initialized in three ways.
  mystring_1 =  "1. I am String in SystemC";
  mystring_2 = ("2. I am String in SystemC");
  mystring_3 = {"3. I am String in SystemC"};
  
  cout <<"mystring   = "<< mystring <<endl;
  cout <<"mystring_1 = "<< mystring_1 <<endl;
  cout <<"mystring_2 = "<< mystring_2 <<endl;
  cout <<"mystring_3 = "<< mystring_3 <<endl;
  
  // Terminate simulation
  return 0;
}
