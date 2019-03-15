#include <iostream>
#include <functional>
#include <thread>
#include <future>
#include <chrono>

void print_int_ref(std::future<int>& fut){
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	int x=fut.get();
	std::cout << "value: " << x << "\n";
}
void print_int_move(std::future<int> fut){
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	int x=fut.get();
	std::cout << "value: " << x << "\n";
}

int main() {
    std::promise<int> promr;
	std::future<int> futr = promr.get_future();
    std::thread tr(print_int_ref, std::ref(futr));
    promr.set_value(10);
    

	std::promise<int> promm;
	std::future<int> futm = promm.get_future();
	std::thread tm(print_int_move, std::move(futm));
    promm.set_value(10);
	
	
	tr.join();
	tm.join();
	return 0;
}

