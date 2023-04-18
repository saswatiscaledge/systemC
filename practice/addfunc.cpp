#include <systemc.h>
//function add, to add two integer numbers
int add(int a,int b) {
	return a+b;
}
int sc_main(int argc,char* argv[]) {
	int x,y,z;
	x = 10;
	y = 20;
	z=add(x,y);
	cout<<"return x+y ="<<z<<endl;
	return 0;
}

