#include <iostream>

class A{

	public:
		void operator() () {
			std::cout << "A operator" << std::endl;
		}

		void operator() (int a) {
			std::cout << "A operator " << a << std::endl;
		}
};

int main(int argc, char** argv) {
	A a;
	a();
	a(1);

}
