#include "AbstractHandler.h"
#include "SimpleFactory.h"
#include <thread>

int main(int argc, char** argv) {
	ManageHandler *manage = new ManageHandler();
	std::thread manage_thread = std::thread(&ManageHandler::run, manage);
	manage_thread.join();
}

/*int main(int argc, char** argv) {
	AbstractFactory* factory = new SimpleFactory();
	
	AbstractHandler* handler = factory->createHandler(1);
	handler->run();
	handler->change_page();
	delete handler;
	handler = NULL;

	handler = factory->createHandler(2);
    handler->run();
	delete handler;
	handler = NULL;

	handler = factory->createHandler(3);
    handler->run();
	delete handler;
	handler = NULL;

	handler = factory->createHandler(4);
    handler->run();
	delete handler;
	handler = NULL;
	
	handler = factory->createHandler(5);
    handler->run();
	delete handler;
	handler = NULL;
	
	handler = factory->createHandler(6);
    handler->run();
	delete handler;
	handler = NULL;

	return 0;
}*/
