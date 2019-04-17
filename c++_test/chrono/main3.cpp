#include <iostream>
#include <thread>
#include <chrono>

#define SPAN (5)

int main(int argc, char** argv) {
	auto start = std::chrono::system_clock::now();

	int elapsed_seconds = 0;
	
	while(elapsed_seconds < SPAN ) {
		std::cout << "..";
		std::this_thread::sleep_for(std::chrono::seconds(1));
		
		auto end = std::chrono::system_clock::now();
		std::chrono::duration<double> elapsed = end-start;
		elapsed_seconds = elapsed.count();
		std::cout << "elapsed_seconds:" << elapsed_seconds << std::endl;
	}

	std::cout << "elapsed.";
	
}
