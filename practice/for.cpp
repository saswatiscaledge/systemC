//one example

/*#include "systemc.h"
int sc_main (int argc, char* argv[]) {

  //for-loop
  for(int i=0; i<4; i++)
  {
    cout <<" Value of i = "<<i<<endl;
  }
    
  // Terminate simulation
  return 0;
}*/

//2nd example

/*#include <systemc.h>
int sc_main(int argc,char* argv[]) {
	for(int j=0,i=3;j<5;j++)
	{
		if(j==i)
			cout<<"Value j equals to Value of i. j ="<<j<<" i ="<<i<<endl;
		else
			cout<<"Value j="<<j<<endl;
	}
	return 0;
}*/

//3rd example

#include "systemc.h"
int sc_main (int argc, char* argv[]) {

  //for-loop
  for ( int j=0,i=4;j<4;j++,i--)
  {
    cout <<" j="<<j<<" i="<<i<<endl;
  }
    
  // Terminate simulation
  return 0;
}




