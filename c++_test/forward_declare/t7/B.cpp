#include "B.h"

#include "A.h"
#include <iostream>

using namespace std;

B::B() {
    cout << "create B" << endl;
	a = std::make_shared<A>();
}

B::~B() {
    cout << "destroy B" << endl;
}

void B::test() {
    cout << "B test" << endl;
	a->test();
}


