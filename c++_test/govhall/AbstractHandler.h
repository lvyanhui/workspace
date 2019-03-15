#ifndef _HANDLER_H_
#define _HANDLER_H_

#include <iostream>
#include <thread>

class AbstractHandler {
public:
	AbstractHandler();
	virtual ~AbstractHandler();
public:
    virtual void init();
	virtual void run() = 0;
    void change_page() {
		std::cout << "	change page" << std::endl;	
		std::cout << "	a: "<< a << ", b:"<< b << std::endl;	
	}
public:
	int a;
	int b;
};

class UsherHandler : public AbstractHandler {
public:
    UsherHandler();
 	virtual ~UsherHandler();

public:
    virtual void init();
	void run();
	void test();
};

class LineHandler : public AbstractHandler {
public:
	LineHandler();
	virtual ~LineHandler();

public:
	void run();
};

class PatrolHandler : public AbstractHandler {
public:
	PatrolHandler();
	virtual ~PatrolHandler();

public:
	void run();
};

class TourHandler : public AbstractHandler {
public:
	TourHandler();
	virtual ~TourHandler();

public:
	void run();
};

class StandbyHandler : public AbstractHandler {
public:
	StandbyHandler();
	virtual ~StandbyHandler();

public:
	void run();
};

class ChargeHandler : public AbstractHandler {
public:
	ChargeHandler();
	virtual ~ChargeHandler();

public:
	void run();
};

class ManageHandler : public AbstractHandler {
public:
	ManageHandler();
	virtual ~ManageHandler();

public:
	void run();
    void start();
	void stop();

public:
	std::thread main_thd_;
	std::thread work_thd_;
};
#endif
