#include <systemc.h>
int sc_main(int argc,char* argv[]) {
	for(int i=0;i<8;i++) {
		cout<<"Value of i:"<<i<<endl;
		if(i==4) {
			cout<<"calling break"<<endl;
			break;
		}
	}
	return 0;
}
