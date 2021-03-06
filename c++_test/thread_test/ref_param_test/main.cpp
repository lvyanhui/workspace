#include <thread>
#include <iostream>
#include <chrono>

void work2_handle() {
	std::chrono::seconds sec(3);
	while(1) {
		std::cout << "working 2 ..." << std::endl;
		std::this_thread::sleep_for(sec);
	}
}

void work_handle(int i, bool& terminate) {
	std::cout << "work_thread: "  << i <<", " <<std::this_thread::get_id() << "\n";
	
    std::chrono::seconds sec(1);
	while(1) {
		if(terminate)
			break;
		std::cout << "working ..." <<terminate <<std::endl;
		std::this_thread::sleep_for(sec);
	}
	std::cout << "work terminate" << std::endl;
}

int main(int argc, char** argv) {
	std::thread work_thread;
    std::thread chat_thread;
    std::thread find_waker_thread;
	
    bool terminate = false;
 
	std::chrono::seconds sec(3);
	for(int i=0; i<3; i++) {
	    if(work_thread.joinable())
			work_thread.join();
        else {
		    terminate = false;	
			work_thread = std::thread(work_handle, i, std::ref(terminate));
		}
		
		std::this_thread::sleep_for(sec);
		terminate = true;	
	    work_thread.join();
		//work_thread[i].join();	
	}   

}

#if 0
int main(int argc, char** argv) {
	std::thread work_thread = std::thread(work_handle);
    std::thread chat_thread;
    std::thread find_waker_thread;
	
	std::cout << "work_thread: " << work_thread.get_id() << "\n";
    //std::this_thread::yield();
	
	std::chrono::seconds sec(1);
	std::this_thread::sleep_for(sec);
    
    work_thread = std::move(std::thread(work2_handle));
	
    if(work_thread.joinable()) {
		std::cout << "work thread join" << std::endl;
		work_thread.join();
	}
}
#endif
