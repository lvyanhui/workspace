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
    work_thd_ = std::thread(&AbstractHandler::run, handler);
	work_thd_.join();

	handler->change_page();
	delete handler;
	handler = NULL;

	handler = factory->createHandler(2);
    work_thd_ = std::thread(&AbstractHandler::run, handler);
	work_thd_.join();
	handler->change_page();
	delete handler;
	handler = NULL;

	handler = factory->createHandler(3);
    work_thd_ = std::thread(&AbstractHandler::run, handler);
	work_thd_.join();
	delete handler;
	handler = NULL;

	handler = factory->createHandler(4);
    work_thd_ = std::thread(&AbstractHandler::run, handler);
	work_thd_.join();
	delete handler;
	handler = NULL;

	handler = factory->createHandler(5);
    work_thd_ = std::thread(&AbstractHandler::run, handler);
	work_thd_.join();
	delete handler;
	handler = NULL;

	handler = factory->createHandler(6);
    work_thd_ = std::thread(&AbstractHandler::run, handler);
	work_thd_.join();
	delete handler;
	handler = NULL;
}

void ManageHandler::start(){
	//main_thd_ = std::thread(std::bind(&ManageHandler::run, this)); //ok	
	main_thd_ = std::thread(&ManageHandler::run, this);	
}

void ManageHandler::stop(){
	if(work_thd_.joinable())
		work_thd_.join();
	if(main_thd_.joinable())
		main_thd_.join();
}

