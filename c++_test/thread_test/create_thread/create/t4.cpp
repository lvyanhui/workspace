#include <iostream>
#include <thread>

class MyFunctor {
public:
    void operator() (){
        std::cout << "myfunctor\n";	
    }
};

int main() {
    /*MyFunctor functor;
	std::thread t(functor);  */

	std::thread t((MyFunctor()));
	std::cout << "main thread\n";
	t.join();
	return 0;
}

