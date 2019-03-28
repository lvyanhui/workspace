#include "A.h"
#include <iostream>

using namespace std;

A::A() {
    cout << "create A" << endl;
}

A::~A() {
    cout << "destroy A" << endl;
}

void A::test() {
    cout << "A test" << endl;
}

