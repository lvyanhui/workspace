#include <iostream>
#include <chrono>
#include <thread>
 
 int main()
 {
	     using namespace std::chrono_literals; // C++14
		     std::cout << "Hello waiter" << std::endl; // 有意冲入
			     auto start = std::chrono::high_resolution_clock::now();
				     std::this_thread::sleep_for(2s);
					     auto end = std::chrono::high_resolution_clock::now();
						     std::chrono::duration<double, std::milli> elapsed = end-start;
							     std::cout << "Waited " << elapsed.count() << " ms\n";
 }
