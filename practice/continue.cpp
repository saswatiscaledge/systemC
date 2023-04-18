#include <systemc.h>
int sc_main(int argc, char* argv[]) {
	for(int i=0;i<5;i++) {
		cout<<"Before continue, value of i="<<i<<endl;
		if((i > 1) && (i < 4)) {
			cout <<"     Calling continue"<<endl;
			continue;
		}
		cout<<"After continue, value of i="<<i<<endl;
	}
	return 0;
}

