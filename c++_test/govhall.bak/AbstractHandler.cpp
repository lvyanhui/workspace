#include "AbstractHandler.h"

AbstractHandler::AbstractHandler() {
}

AbstractHandler::~AbstractHandler(){
}

UsherHandler::UsherHandler(){
}

UsherHandler::~UsherHandler(){
}

void UsherHandler::run(){
	std::cout << "usher run" << std::endl;	
}

LineHandler::LineHandler() {
}

LineHandler::~LineHandler() {
}

void LineHandler::run() {
	std::cout << "line run" << std::endl;	
}

PatrolHandler::PatrolHandler() {
}

PatrolHandler::~PatrolHandler() {

}

void PatrolHandler::run(){
	std::cout << "patrol run" << std::endl;	
}

TourHandler::TourHandler(){
}

TourHandler::~TourHandler(){	
}

void TourHandler::run(){
	std::cout << "tour run" << std::endl;	
}

StandbyHandler::StandbyHandler(){
}

StandbyHandler::~StandbyHandler(){
}

void StandbyHandler::run(){
	std::cout << "standby run" << std::endl;	
}

ChargeHandler::ChargeHandler(){
}

ChargeHandler::~ChargeHandler(){
}

void ChargeHandler::run(){
	std::cout << "standby run" << std::endl;	
}

