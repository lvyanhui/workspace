#include <thread>
#include <iostream>
#include <chrono>
#include <condition_variable>

std::mutex mtx;
std::condition_variable produce, consume;
int cargo = 0;

void consumer() {
	std::unique_lock<std::mutex> lck(mtx);
	
	while(cargo == 0) consume.wait(lck);

	std::cout << cargo << "\n";

	cargo = 0;

	produce.notify_one();
}

void producer(int id) {
	std::unique_lock<std::mutex> lck(mtx);
    while(cargo != 0) produce.wait(lck);

	cargo = id;
	consume.notify_one();
}

int main(int argc, char** argv) {
	std::thread consumers[10], producers[10];
	
	for(int i=0; i<10; i++) {
		consumers[i] = std::thread(consumer);
		producers[i] = std::thread(producer, i+1);
	}

	for(int i=0; i<10; i++) {
		producers[i].join();
		std::cout << "producers join" << i << "\n";
		consumers[i].join();
		std::cout << "consumers join" << i << "\n";
	}
	return 0;
}
