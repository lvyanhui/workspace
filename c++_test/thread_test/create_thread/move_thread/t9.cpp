#include <iostream>
#include <thread>
#include <string>
#include <chrono>

//std::chrono::milliseconds dura(100);
//std::this_thread::sleep_for(dura);

void thread_function() {
    std::cout << "thread function\n";	
}

int main() {

    std::thread t(&thread_function); 
	
	std::cout << "main thread\n";
	//std::thread t2 = t;  //compile error;

	std::thread t2 = move(t);
	t2.join();
	return 0;
}

