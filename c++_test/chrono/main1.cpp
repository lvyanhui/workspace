#include <iostream>
#include <thread>
#include <chrono>

#define SPAN (5)

int main(int argc, char** argv) {

	std::chrono::system_clock::time_point tp = std::chrono::system_clock::now();
	std::chrono::system_clock::duration dtn = tp.time_since_epoch();
	int elapsed_seconds = dtn.count() * std::chrono::system_clock::period::num / std::chrono::system_clock::period::den;
	std::cout << "elapsed: " << elapsed_seconds << std::endl;
	while(elapsed_seconds < SPAN ) {
		std::cout << "..";
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
		
	std::cout << "elapsed.";
}
