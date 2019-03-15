#include <iostream>
#include <thread>
//#include <functional>

class A{
public:
	A(){}
	~A(){t.join();}

	void thread_function() {
    	std::cout << "thread function\n";	
	}

	void start() {
		//t = std::thread(std::bind(&A::thread_function, this));
		t = std::thread(&A::thread_function, this);
	}

private :
	std::thread t;
};

int main() {
    //std::thread t(&thread_function);  //ok
    //std::thread t(thread_function);     //ok, too
	A a;
    a.start();
	std::cout << "main thread\n";
	//t.join();
	return 0;
}

