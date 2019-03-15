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

int add_event(int count){

	std::unique_lock<std::mutex > lock(mutex_);
	cv_.wait(lock,[&]{data_.push_back(count);  return true;});	
	lock.unlock();
	cv_.notify_one();

	return 0;
}

int producer() {

	while(true) {
 		count++;
		std::cout<<"produce: " << count << std::endl;
	    add_event(count);
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}

	return 0;
}

int get_event() {
	std::unique_lock<std::mutex> lock(mutex_);
	while(data_.empty())
		cv_.wait(lock);

	int data = data_.front(); 
	data_.pop_front(); 

	lock.unlock();

	return data;
}

int consumer() {
	while(true) {
		int data = get_event();
	    std::cout << "consumer: " << data << std::endl;
	}

	return 0;
}

int main(int argc, char** argv) {
	std::future<int > futp = std::async(std::launch::async, producer);
	std::future<int > futc = std::async(std::launch::async, consumer);

	while(1);

	return 0;
}
