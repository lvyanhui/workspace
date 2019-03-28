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

void B::test1(A& a) {

}

void B::test2(const A& a) {

}

void B::test3(A* y){

}

void B::test4(std::shared_ptr<A> z){

}

