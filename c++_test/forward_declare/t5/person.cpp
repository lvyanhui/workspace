#include <iostream>
#include "./person.h"
using namespace std;
Person::Person(void){
    cout<< "create person." << endl;
}

Person::~Person(void){
    cout<< "destroy person." << endl;
}

void Person::eat(void){
    cout<< "person eat." << endl;
}
