#include <systemc.h>

void myFunction(string country = "Norway") {
	cout << country  << endl;
}
int sc_main(int argc,char* argv[]) {
	myFunction("India");
	myFunction("USA");
	myFunction();
	myFunction("China");
	return 0;
}
