#include <thread>
#include <iostream>
#include <chrono>
#include <condition_variable>

std::mutex mtx;
std::condition_variable produce, consume;
int cargo = 0;

void consumer() {
    while(1) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		std::unique_lock<std::mutex> lck(mtx);
		consume.wait(lck);
		std::cout << cargo << "\n";
		cargo = 0;

	}
}

void producer(int id) {
	while(1) {
		//std::unique_lock<std::mutex> lck(mtx);
    	//while(cargo != 0) produce.wait(lck);
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
		id++;
		
		std::unique_lock<std::mutex> lck(mtx);
		cargo = id;
		consume.notify_one();
	}
}

int main(int argc, char** argv) {

	std::thread consumers, producers;

	
	consumers = std::thread(consumer);
	producers = std::thread(producer, 1);

	producers.join();
	std::cout << "producers join"  << "\n";
	consumers.join();
	std::cout << "consumers join" << "\n";

	return 0;
}
