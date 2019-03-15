#pragma once
#include <iostream>
#include <queue>
#include <mutex>
#include <condition_variable>

template<class T> 
class BlockQueue {
	public:
		BlockQueue() 
			: queue_()
			  , mutex_()
			  , cond_() {

			  }
		~BlockQueue() { 
		}

		void push(const T& t) {
			{
				std::unique_lock<std::mutex > lock(mutex_);
				queue_.push(t);
			}
			cond_.notify_all();
		}

		T pop() {
			std::unique_lock<std::mutex > lock(mutex_);
			while(queue_.empty()) {
				cond_.wait(lock);	
			}
			
			T front(queue_.front());
			queue_.pop();
			return front;
		}
	private:
		std::queue<T> queue_;
		std::mutex mutex_;
		std::condition_variable cond_;
};

template<class T>
class BlockQueue<T* > {
	public:
		BlockQueue()
		: queue_()
		, mutex_()
		, cond_() {
		}
		~BlockQueue(){
			}

		void push(T* t) {
			{
				std::unique_lock<std::mutex> lock(mutex_);
				queue_.push(t);
			}	
			cond_.notify_all();
		}

		T* pop() {
			std::unique_lock<std::mutex> lock(mutex_);
			while( queue_.empty()) {
				cond_.wait(lock);	
			}
			T* front(queue_.front());
			queue_.pop();
			return front;
		}
private:
	std::queue<T* > queue_;
	std::mutex mutex_;
	std::condition_variable cond_;
};

