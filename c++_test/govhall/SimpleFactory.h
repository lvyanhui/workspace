#ifndef _SIMPLEFACTORY_H_
#define _SIMPLEFACTORY_H_

#include <iostream>
#include "AbstractHandler.h"

class AbstractFactory{
public:
	AbstractFactory();
	virtual ~AbstractFactory();

public:
	virtual AbstractHandler* createHandler(int type) = 0;

};

class SimpleFactory:public AbstractFactory{
public:
	SimpleFactory();
	~SimpleFactory();
public:
	AbstractHandler* createHandler(int tpye);
};

#endif
