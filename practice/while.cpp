#include <systemc.h>
int sc_main(int argc,char* argv[]) {
	int a = 20;
	int b = 15;
	while(a>b) {
		cout<<"a is greater than b, a ="<<a<<" b ="<<b<<endl;
		a--;
	}
	cout <<" b is greater than a "<<endl;
	return 0;
}
