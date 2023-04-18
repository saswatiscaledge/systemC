#include <systemc.h>
int sc_main(int argc,char* argv[]) {
	//declaration
	enum Colors{red,green=2,blue,white=5,black,orange};
	Colors mycolor;
	mycolor=blue;
	cout<<"mycolor="<<mycolor<<endl;
	mycolor=black;
	cout<<"mycolor="<<mycolor<<endl;
	return 0;
	//this is one type 
	/*enum Colors{red,green,blue,white,black,orange} Colors_t;
	Colors mycolor;
	Colors_t=white;
	mycolor=blue;
	cout <<"Colors_t   = "<< Colors_t <<endl;
	cout <<"mycolor   = "<< mycolor <<endl;
	return 0;*/
}
 	

