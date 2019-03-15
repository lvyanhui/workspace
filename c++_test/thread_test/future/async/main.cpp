#include <thread>
#include <chrono>
#include <future>
#include <iostream>

bool is_prime(int x) {
	for(int i=2; i<x; i++) {
		if(x%i == 0) return false;
	}

    return true;

}

int main(int argc, char** argv) {

	std::future<bool > fut = std::async(is_prime, 444444443);
	std::cout << "checking, please wait";

    std::chrono::milliseconds span(100);

	while(fut.wait_for(span) == std::future_status::timeout) 
		std::cout << '.' << std::flush;
	
	bool x = fut.get();

	std::cout << "\n444444443" << (x?" is ":" is not ") << "prime.\n";
	return 0;
}

