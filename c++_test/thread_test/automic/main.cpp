#include <iostream>
#include <atomic>
#include <thread>
#include <vector>

std::atomic<bool> ready(false);
std::atomic_flag winner = ATOMIC_FLAG_INIT;

void countlm(int id) {
	while(!ready) {
		std::this_thread::yield();
	}
	
	for(volatile int i=0; i<1000000; ++i) {	}
	if(!winner.test_and_set()) {
			std::cout << "thread #" <<id << "won!\n";	
	}
}

int main(int argc, char** argv) {
	
	std::vector<std::thread> threads;
	std::cout << "spawning 10 threads that count to 1 million...\n";
	for (int i=1; i<=10; ++i) {
		threads.push_back(std::thread(countlm, i));
	}

	ready = true;

	for(auto& th : threads) th.join();

	return 0;
}

