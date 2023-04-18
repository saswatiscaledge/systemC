#include <systemc.h>

//1 type
/*int sc_main (int argc,char* argv[]) {
	//variable declarartion
	int a;
	float b,c;

	//initializtion
	a=10;
	b=20.3;

	//addition
	c=a+b;

	cout <<"Value of a = "<< c <<endl;
	return 0;*/
//2 type
int sc_main (int argc,char* argv[]) {
	int a=10;
	float b{2.8};
	int c(1.3);

	cout <<"Value of a = "<< a <<endl;
	cout <<"Value of b = "<< b <<endl;
	cout <<"Value of c = "<< c <<endl;
	return 0;

}

