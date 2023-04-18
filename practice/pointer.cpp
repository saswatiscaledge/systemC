#include <systemc.h>

int sc_main(int argc,char* argv[]) {
	string food = "pizza";//food variable of type string
	string* ptr = &food;//A pointer variable, with the name ptr, that stores the address of food
        cout << food << endl;
	cout << &food << endl;//&operator to store the memory address
	//Reference: Output the memory address of food with the pointer
	cout << ptr << endl;//ptr holds the value of food's memory address.
	//Dereference: Output the value of food with the pointer
        cout << *ptr << endl;
	*ptr = "Chowmin";//changing the food name from pizza to Chowmin
	cout << *ptr << endl;
	cout << food <<endl;
	return 0;
}


