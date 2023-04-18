#include <systemc.h> 
int sc_main(int argc,char* argv[]) {
	char a[]="Hello World";
	char b[5];
	b[0]='H';
	b[1]='e';
	b[2]='l';
	b[3]='l';
	b[4]='o';
	cout<<"value of a:"<<a<<endl;
	cout<<"value of b:"<<b<<endl;
	return 0;
}


//below initializations types are not allowed
	/*b = "Hello";
	b = {'H','e','l','l','o'};*/



