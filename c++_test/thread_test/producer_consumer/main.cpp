#include <thread>
#include <mutex>
#include <condition_variable>
#include <iostream>
#include <chrono>
#include <deque>
#include <future>

std::mutex mutex_;
std::condition_variable cv_;

int count;
std::deque<int> data_;


int producer() {

	while(true) {
		std::unique_lock<std::mutex > lock(mutex_);
		cv_.wait(lock,[&]{count++; data_.push_back(count); std::cout<<"produce: " << count << std::endl; return true;});	
		lock.unlock();
		cv_.notify_one();

		std::this_thread::sleep_for(std::chrono::seconds(1));
		
	}

	return 0;
}

int consumer() {
	while(true) {
		std::unique_lock<std::mutex> lock(mutex_);
		while(data_.empty())
			cv_.wait(lock);
		    //std::this_thread::sleep_for(std::chrono::seconds(5));

		int data = data_.front(); 
		data_.pop_front(); 
		std::cout << "consumer: " << data << std::endl;
		
		lock.unlock();
		
	}

	return 0;
}

int main(int argc, char** argv) {
	std::future<int > futp = std::async(std::launch::async, producer);
	std::future<int > futc = std::async(std::launch::async, consumer);

	while(1);

	return 0;
}
