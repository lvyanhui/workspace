#include <iostream>

using namespace std;

class Base {
	public:
		Base(){cout<< "base " << endl;}
		virtual ~Base(){cout << "destroy base" << endl;}
	
};

class Derive: public Base {
	public:
		Derive(){cout<< "derive " << endl;}
		~Derive(){cout << "destroy derive" << endl;}
	
};

int main(int argc, char** argv) {
    Base* b = new Derive();
	delete b;
}
