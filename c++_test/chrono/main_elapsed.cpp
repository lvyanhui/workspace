#include <iostream>
#include <thread>
#include <chrono>

class A {
	class TimeElapse {
		public:
			//TimeElapse(){}
			//~TimeElapse(){}

			void set_start(const std::chrono::time_point<std::chrono::steady_clock>& tick) {start_ = tick;}
			void set_end(const std::chrono::time_point<std::chrono::steady_clock>& tick) {end_ = tick;}
			int get_elapsed() {
				std::chrono::duration<double> elapsed = end_-start_;
				return elapsed.count();
			}   

		private:
			std::chrono::time_point<std::chrono::steady_clock> start_;
			std::chrono::time_point<std::chrono::steady_clock> end_;
			//std::chrono::duration<double> elapsed_;
	};

	public:
		TimeElapse te;
};

int main(int argc, char** argv) {
	A a;
	a.te.set_start(std::chrono::steady_clock::now());
	std::this_thread::sleep_for(std::chrono::seconds(2));
	a.te.set_end(std::chrono::steady_clock::now());
	std::cout << "elapsed time : "<< a.te.get_elapsed() << std::endl; 
}

/*int main(int argc, char** argv) {
	TimeElapse te;
	te.set_start(std::chrono::steady_clock::now());
	std::this_thread::sleep_for(std::chrono::seconds(2));
	te.set_end(std::chrono::steady_clock::now());
	std::cout << "elapsed time : "<< te.get_elapsed() << std::endl; 
}*/
