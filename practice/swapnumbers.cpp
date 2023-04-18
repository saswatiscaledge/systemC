#include <systemc.h>

void swapNums(int &x, int &y) {
  int z = x;
  x = y;
  y = z;
}

int sc_main(int argc,char* argv[]) {
  int firstNum = 10;
  int secondNum = 20;

  cout << "Before swap: " << endl;
  cout << firstNum  << secondNum << endl;

  // Call the function, which will change the values of firstNum and secondNum
  swapNums(firstNum, secondNum);

  cout << "After swap: " << endl;
  cout << firstNum  << secondNum << endl;

  return 0;
}
