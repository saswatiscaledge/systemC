#include <systemc.h>

void MyFunction() {
		cout << "I just got executed!" <<endl;
	}
int sc_main(int argc,char* argv[]) {
	MyFunction();//call the function
        //calling the function multiple times
	MyFunction();
	MyFunction();
	return 0;
}

