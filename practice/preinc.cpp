#include <systemc.h>
int sc_main(int argc,char* argv[]) {
	int a=5;
	cout<<"Value of a="<<++a<<endl;//preincrement
	cout<<"Value of a="<<a++<<endl;//postincrement
	return 0;
}

