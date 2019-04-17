#include <iostream>
#include <chrono>
#include <thread>

int main()
{
	std::cout << "Hello waiter\n" << std::flush;
	//auto start = std::chrono::high_resolution_clock::now();
	//auto start = std::chrono::system_clock::now();
	auto start = std::chrono::steady_clock::now();
	std::this_thread::sleep_for(std::chrono::seconds(2));
	//auto end = std::chrono::high_resolution_clock::now();
	//auto end = std::chrono::system_clock::now();
	auto end = std::chrono::steady_clock::now();
	
	std::chrono::duration<double, std::milli> elapsed = end-start;
	std::cout << "Waited " << elapsed.count() << " ms\n";
}
