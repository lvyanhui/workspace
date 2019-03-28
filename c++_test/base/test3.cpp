#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>

using namespace std;

class A {
	public:
		A() {
			need_to_terminate_ = false;
			cout<< "A " << endl;
		}
		
		~A(){
			if(thread_.joinable())
				thread_.join();

			cout << "destroy A" << endl;
		}
		
		void start() {
			cout << "A start" << endl;
			thread_ = std::thread(&A::run, this);
		}
		void stop() {
			cout << "A stop" << endl;
			need_to_terminate_ = true;
		}
		void run() {
			cout << "A run" << endl;
			while(!need_to_terminate_) {
				std::this_thread::sleep_for(std::chrono::milliseconds(200));
			}
			cout << "A run exit" << endl;
		}
	
	private:
		std::thread thread_;
		std::atomic<bool> need_to_terminate_;
};

class Base {
	public:
		Base(){
			cout<< "base " << endl;
		    a.start();
		}

		~Base() {
			a.stop();
			cout << "destroy base" << endl;
		}
	
	private:
		A a;
};

int main(int argc, char** argv) {
	Base* b = new Base();
    std::this_thread::sleep_for(std::chrono::seconds(1));

	delete b;
}
