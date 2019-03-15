#include <iostream>
#include <chrono>
#include <thread>
#include <future>

class Stopable{
	public:
		Stopable() : futureObj(exitSignal.get_future()) {
		}

		Stopable(Stopable && obj) : exitSignal(std::move(obj.exitSignal)), futureObj(std::move(obj.futureObj)) {
			std::cout << "Move Constructor is called" << std::endl;
		}

		Stopable& operator=(Stopable && obj) {
			std::cout << "Move Assignment is called" << std::endl;
			exitSignal = std::move(obj.exitSignal);
			futureObj = std::move(obj.futureObj);
			return *this;
		}

		virtual void run() = 0;

		void operator()() {
			run();
		}

		bool stopRequested() {
			if(futureObj.wait_for(std::chrono::milliseconds(0)) == std::future_status::timeout)	
				return false;

			return true;
		}

		void stop() {
			exitSignal.set_value();	
		}

	private:
		std::promise<void> exitSignal;
		std::future<void> futureObj;

};

class MyTask : public Stopable {
	public:
		void run() {
			std::cout << "Task start" << std::endl;

			while(stopRequested() == false) {
				std::cout << "Doing Some Work" << std::endl;
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			}
			std::cout << "Task End" << std::endl;
		}
};

int main(int argc, char** argv) {
	MyTask task;

	std::thread th([&](){
		task.run();		
	});

	std::this_thread::sleep_for(std::chrono::seconds(10));

    std::cout << "Asking Task to Stop" << std::endl;
	task.stop();

	th.join();

	std::cout << "Thread joined" << std::endl;
	std::cout << "Exiting Main Function" << std::endl;
 	return 0;
}

