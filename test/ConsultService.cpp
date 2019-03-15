#include <iostream>
#include "ConsultService.h"

SingleConsultService::SingleConsultService() {
	
}

SingleConsultService::~SingleConsultService() {
	
}

ContinuousCousultService::ContinuousConsultService(){}
ContinuousCousultService::~ContinuousConsultService(){}

int main(int argc, char** argv) {
	ConsultService *cs = new ContinuousCousultService();
	delete cs;
}
