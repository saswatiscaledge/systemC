#include <systemc.h>
void display1();
void display2();
//function display1()
void display1() {
	display2();
}
//function display2()
void display2() {
	display1();
}
int sc_main(int argc,char* argv[]) {
	cout<<"Inside main"<<endl;
	return 0;
}
