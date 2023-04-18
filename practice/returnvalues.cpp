#include <systemc.h>

int myFunction(int x) {
	return 5+x;
}

int sc_main(int argc,char* argv[]) {
	cout << myFunction(3);
	return 0;
}
