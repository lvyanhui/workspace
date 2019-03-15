#include "AbstractHandler.h"
#include "SimpleFactory.h"

ManageHandler::ManageHandler(){
}

ManageHandler::~ManageHandler(){
}

void ManageHandler::run(){
	std::cout << "manage run" << std::endl;

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

}

void ManageHandler::start(){
	th_ = std::thread(&ManageHandler::thread, this);	
}

void ManageHandler::stop(){
	th_.join();
}
/*int main(int argc, char** argv){

  }*/
