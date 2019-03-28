#include <iostream>

using namespace std;

class Base {
	public:
		Base(){cout<< "base " << endl;}
		//virtual ~Base(){cout << "destroy base" << endl;}
		~Base(){cout << "destroy base" << endl;}
	
};

int main(int argc, char** argv) {
	Base* b = new Base();
	delete b;
}
