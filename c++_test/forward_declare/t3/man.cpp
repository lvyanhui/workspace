#include "./man.h"

Man::Man(Person* child){
   this->child = child;	
}

Man::~Man(void){

}

void Man::test(void){
	child->eat();
}
