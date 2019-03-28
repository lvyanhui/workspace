#include "B.h"

#include "A.h"
#include <iostream>

using namespace std;

B::B() {
    cout << "create B" << endl;
	a = new A();
}

B::~B() {
    cout << "destroy B" << endl;
    delete a;
}

void B::test() {
    cout << "B test" << endl;
	a->test();
}


