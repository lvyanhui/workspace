#include <thread>
#include <iostream>
#include <chrono>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
int value;

void read_value() {
	std::cin >> value;
	cv.notify_one();
}

int main(int argc, char** argv) {
	std::thread th(read_value);

	std::cout << "Please enter an integer: " << "\n";
	
	std::mutex mtx;
	std::unique_lock<std::mutex> lck(mtx);
	while(cv.wait_for(lck, std::chrono::seconds(1)) == std::cv_status::timeout) {
		std::cout << "." << std::endl;
	}	

	std::cout << "You entered: " << value << "\n";

    if(th.joinable()) {
		th.join();
	}

	return 0;
}
