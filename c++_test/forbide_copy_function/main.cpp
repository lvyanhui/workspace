#include <iostream>

using namespace std;

class Test {
public:
    Test() {
    }
    Test(const Test&) = delete;
    Test& operator = (const Test&) = delete;
};

class Test1 : public Test{

};

int main()
{
    Test test;
    //Test t2 = test;//编译错误
    Test1 t1;
    //Test1 t2 = t1;//编译错误
    return 0;
}

