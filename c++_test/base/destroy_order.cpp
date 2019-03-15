#include <iostream>

using namespace std;

class A {
	public:
		A(){cout<< "A " << endl;}
		~A(){cout << "destroy A" << endl;}
};

class B {
	public:
		B(){cout<< "B " << endl;}
		~B(){cout << "destroy B" << endl;}
};


class Base {
	public:
		Base(){cout<< "base " << endl;}
		//virtual ~Base(){cout << "destroy base" << endl;}
		~Base(){cout << "destroy base" << endl;}
	
	private:
		A a;
};

class Derive: public Base {
	public:
		Derive(){cout<< "derive " << endl;}
		~Derive(){cout << "destroy derive" << endl;}
	
	private:
	    B b;
};

int main(int argc, char** argv) {
	Base* b = new Derive();
	delete b;
	//Derive d;	
}
