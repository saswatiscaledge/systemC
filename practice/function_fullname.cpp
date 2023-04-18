#include <systemc.h>

void myFunction(string fname,int age) {//fname is parameter
	cout << fname << " Dubey. " << age << "  years old." << endl;
}
int sc_main(int argc,char* argv[]) {
	myFunction("Lima", 25);//Lima and Anjana are arguments
	myFunction("Anjana", 24);
	return 0;
}
