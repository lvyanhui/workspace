#include <thread>
#include <chrono>
#include <future>
#include <iostream>


void is_prime(int x) {
	for(int i=2; i<x; i++) {
		if(x%i == 0) { 
			std::cout << x << '\n';
			return;
		}
			//return false;
	}

    //return true;
    return ;

}

int main(int argc, char** argv) {

	std::future<void > fut = std::async(is_prime, 444444443);
	std::cout << "checking, please wait";

    std::chrono::milliseconds span(100);

	while(fut.wait_for(span) == std::future_status::timeout) 
		std::cout << '.' << std::flush;
	
	//bool x = fut.get();
	fut.get();

	bool x;
	std::cout << "\n444444443" << (x?"is":"is not") << "prime.\n";
	return 0;
}

