#include <iostream>
#include <thread>
#include <string>
#include <chrono>

void thread_function(std::string s) {
    std::cout << "thread function ";	
	std::cout << "message is = " << s << std::endl;
	s = "Hello Monkey";
}

int main() {
    std::string s= "Hello Kitty";

    //std::thread t(&thread_function, s); //compile failed 
    std::thread t(&thread_function, std::move(s)); 
    std::chrono::milliseconds dura(100);
    std::this_thread::sleep_for(dura);
	
	std::cout << "main thread message = " << s << std::endl;
	t.join();
	return 0;
}

