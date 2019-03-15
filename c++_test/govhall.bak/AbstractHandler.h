#ifndef _HANDLER_H_
#define _HANDLER_H_

#include <iostream>

class AbstractHandler {
public:
	AbstractHandler();
	virtual ~AbstractHandler();
public:
    virtual void run() = 0;
    void change_page() {
		std::cout << "change page" << std::endl;	
	}
};

class UsherHandler : public AbstractHandler {
public:
    UsherHandler();
 	virtual ~UsherHandler();

public:
	void run();
    void start();
	void stop();
};

class LineHandler : public AbstractHandler {
public:
	LineHandler();
	virtual ~LineHandler();

public:
	void run();
    void start();
	void stop();
};

class PatrolHandler : public AbstractHandler {
public:
	PatrolHandler();
	virtual ~PatrolHandler();

public:
	void run();
    void start();
	void stop();
};

class TourHandler : public AbstractHandler {
public:
	TourHandler();
	virtual ~TourHandler();

public:
	void run();
    void start();
	void stop();
};

class StandbyHandler : public AbstractHandler {
public:
	StandbyHandler();
	virtual ~StandbyHandler();

public:
	void run();
    void start();
	void stop();
};

class ChargeHandler : public AbstractHandler {
public:
	ChargeHandler();
	virtual ~ChargeHandler();

public:
	void run();
    void start();
	void stop();
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
	std::thread th_;
};
#endif

/*int main(int argc, char** argv){
	
}*/
