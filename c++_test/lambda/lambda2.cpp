#include <iostream>
using namespace std;


int main() {
	int a = 123;
	int b = 1234;

#if 0	
    //auto f = [a,b] {cout << a <<endl; cout << b << endl;};
	//auto f = [=] {cout << a <<endl; cout << b << endl;};
	//auto f = [=]mutable {cout << a <<endl; a=100; cout << b << endl;}; // error
	//auto f = [=]()mutable {cout << a <<endl; a=100; cout << b << endl;};
	auto f = [=, &b]()mutable {cout << a <<endl; a=100; cout << b << endl;};
	
	//auto f = [&a,&b] {cout << a <<endl; cout << b << endl;};
	//auto f = [&] {cout << a <<endl; cout << b << endl;};

	a = 321;
    b = 4321; 
    f();
	cout << a <<endl;
	cout << b << endl;
#else

	[=]()mutable {cout << a <<endl; a=100; cout << b << endl;}();

#endif
}
