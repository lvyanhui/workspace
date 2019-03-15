#include <thread>
#include <iostream>
#include <chrono>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void print_id(int id) {
	std::unique_lock<std::mutex> lck(mtx);
	while(!ready) cv.wait(lck);
	
	std::cout << "thread " << id << "\n";
}

void go() {
	std::unique_lock<std::mutex > lck(mtx);
	ready = true;
	cv.notify_all();
}

int main(int argc, char** argv) {
	std::thread print_thread;
	
	print_thread = std::thread(print_id, 1);
	std::cout << "print_thread: " << print_thread.get_id() << "\n";

	go();

    if(print_thread.joinable()) {
		print_thread.join();
	}

	return 0;
}
