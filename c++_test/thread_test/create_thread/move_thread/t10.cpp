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
	
	std::cout << "main thread id = " << std::this_thread::get_id() << std::endl;

    std::cout << "t thead id = " << t.get_id() << std::endl;
	std::thread t2 = move(t);
    std::cout << "t2 thead id = " << t2.get_id() << std::endl;

    std::cout << "Number of threads = " << std::thread::hardware_concurrency() << std::endl;	
	t2.join();
	return 0;
}

