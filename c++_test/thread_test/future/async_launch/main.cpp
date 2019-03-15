#include <iostream>
#include <future>
#include <chrono>
#include <thread>

void print_ten(char c, int ms){
    for(int i=0; i<10; ++i) {
		std::this_thread::sleep_for(std::chrono::milliseconds(ms));
		std::cout << c;
	}
}

int main() {
	std::cout << "with launch::async:\n";
	std::future<void> foo = std::async(std::launch::async, print_ten, '*', 100);
	std::future<void> bar = std::async(std::launch::async, print_ten, '@', 200);

    foo.get();
	bar.get();
	std::cout << "\n\n";
	
	std::cout << "with launch::deferred:\n";
	foo = std::async(std::launch::deferred, print_ten, '*', 100);
	bar = std::async(std::launch::deferred, print_ten, '@', 200);

    foo.get();
	bar.get();
	std::cout << "\n\n";
	
	std::cout << "with launch::mixed:\n";
	bar = std::async(std::launch::deferred, print_ten, '@', 200);
	foo = std::async(std::launch::async, print_ten, '*', 100);

	bar.get();
    foo.get();
	std::cout << "\n\n";
	

	return 0;
	
}

