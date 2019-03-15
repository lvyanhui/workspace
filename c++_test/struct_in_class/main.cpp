#include <iostream>
using namespace std;


class A{
	protected:
		typedef struct {
			int m;
		} AS;

	public:

		virtual void show() {
			cout<< "A show" << endl;	
		}	
};

class B: public A {
	public:
		virtual void show() {
			AS as;
			as.m = 100;
			cout << "as.m " << as.m << endl;
		}	
		
		AS get_value() {
			AS as;
			as.m = 200;
			return as;
		}
		
		AS get_value2();
};

//B::AS B::get_value2() {
A::AS B::get_value2() {
	AS as;
	as.m = 300;
	return as;
}

int main (int argc, char** argv) {
	B b;
	b.show();
	cout << "get_value: " << b.get_value().m << endl;
	cout << "get_value2: " << b.get_value2().m << endl;

	return 0;
}
