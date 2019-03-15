#include <future>
#include <iostream>

int main()
{
	std::future<int> myFuture = std::async(std::launch::async, [](){
		std::this_thread::sleep_for(std::chrono::seconds(10));
		return 8;
	});

	// Update Loop for rendering data
	while (true)
	{
		std::cout << (myFuture.valid()?"true":"false" )<< std::endl;
		
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::cout << "Rendering Data" << std::endl;
	
     	if (myFuture.valid()) {

			std::cout << "future valid" << std::endl;
			// Render some info on the screen
			int val = myFuture.get(); // this blocks for 10 seconds
			break;
		}

	}
	std::cout << (myFuture.valid()?"true":"false" )<< std::endl;
	return 0;
}
