#include "./man.h"
#include "person.h"


Man::Man(std::shared_ptr<Person> child){
   this->child = child;	
}

Man::~Man(void){

}

void Man::test(void){
	child->eat();
}
