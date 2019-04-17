#include <memory>
#include <cstddef>
#include <iostream>


class A{
	public:
		A(){std::cout << "A construct" << std::endl;}
		~A(){std::cout << "A deconstruct" << std::endl;}
};

int main(int argc, char** argv) {
	std::shared_ptr<A> a = nullptr;	

	if(a==nullptr)
		std::cout << "1. A is nullptr" << std::endl;

	a = std::make_shared<A>();
	
	if(a==nullptr)
		std::cout << "2. A is nullptr" << std::endl;
	
	a.reset();
	if(a==nullptr)
		std::cout << "3. A is nullptr" << std::endl;
	
	a.reset();
	if(a==nullptr)
		std::cout << "3. A is nullptr" << std::endl;

}
