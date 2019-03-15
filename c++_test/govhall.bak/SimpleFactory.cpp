#include "SimpleFactory.h"

AbstractFactory::AbstractFactory(){
}


AbstractFactory::~AbstractFactory(){
}

SimpleFactory::SimpleFactory(){
}

SimpleFactory::~SimpleFactory(){
}

AbstractHandler* SimpleFactory::createHandler(int type){
	AbstractHandler* temp = NULL;
	switch(type) {
	case 1:
		temp = new UsherHandler();
		break;
	case 2:
		temp = new LineHandler();
		break;
	case 3:
		temp = new PatrolHandler();
		break;
	case 4:
		temp = new TourHandler();
		break;
	case 5:
		temp = new StandbyHandler();
		break;
	case 6:
		temp = new ChargeHandler();
		break;
	default:
		break;
	}

	return temp;
}
