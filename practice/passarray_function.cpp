#include <systemc.h>

int myFunction(int myNumbers[5]) {
	for(int i = 0;i < 5;i++) {
		cout << myNumbers[i] <<endl;
	}
}
int sc_main(int argc,char* argv[]) {
	int myNumbers[5] = {10,20,30,40,50};
	myFunction(myNumbers);
	return 0;
}


