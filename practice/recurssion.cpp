#include<systemc.h>

int sum(int k) {
	if(k > 0) {
		return k + sum(k - 1);
	} else {
		return 0;
	}
}
int sc_main(int argc,char* argv[]) {
	int result = sum(10);
	cout << result << endl;
	return 0;
}
