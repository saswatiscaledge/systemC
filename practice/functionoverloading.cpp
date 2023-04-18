#include <systemc.h>

int plusFuncInt(int x, int y) {
  return x + y;
}

double plusFuncDouble(double x, double y) {
  return x + y;
}

int sc_main(int argc,char* argv[]) {
  int myNum1 = plusFuncInt(8, 5);
  double myNum2 = plusFuncDouble(4.3, 6.26);
  cout << "Int: " << myNum1 << endl;
  cout << "Double: " << myNum2 << endl;
  return 0;
}
