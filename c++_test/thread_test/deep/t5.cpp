#include <iostream>
#include <thread>
//#include <functional>

class A{
public:
	A(){}
	~A(){//t.join();
	}

	void thread_function() {
    	std::cout << "thread function\n";
		set(1, 2);
		std::cout << "sum: " << sum() << std::endl;
	}

	void thread_function2() {
    	std::cout << "thread function\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		//set(1, 2);
		std::cout << "sum: " << sum() << std::endl;
	}

	/*void start() {
		//t = std::thread(std::bind(&A::thread_function, this));
		t = std::thread(&A::thread_function, this);
	}*/

	void set(int ia, int ib) {
		a = ia;
		b = ib;
		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;
	}

	int sum() {
		return a+b;
	}
private :
	//std::thread t;
	int a;
	int b;
};

/*
int main() {
	A a;
    a.start();
	std::cout << "main thread\n";

	return 0;
}
*/
/*
int main() {
	A s;
    std::thread thread(&A::thread_function2, &s);
    //std::thread thread(&A::thread_function2);
	std::this_thread::sleep_for(std::chrono::milliseconds(200));
	s.set(1,2);
	thread.join();

	return 0;
}*/

/*
int main() {
	A* s = new A();
    std::thread thread(&A::thread_function2, s);
	delete s;
	s = NULL;

	std::this_thread::sleep_for(std::chrono::milliseconds(200));
	s->set(1,2);
	thread.join();

	return 0;
}
*/

int main() {
	A s;
    std::thread thread(std::bind(&A::thread_function2, s));
    //std::thread thread(std::bind(&A::thread_function2, &s));
	std::this_thread::sleep_for(std::chrono::milliseconds(200));
	s.set(1,2);
	thread.join();

	return 0;
}
