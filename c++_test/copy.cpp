#include <iostream>
#include <cstring>
#include <string>
using namespace std;
class A{
public:
    A(){};
    A(int x) :x(x){
    };
private:
    int x;
    A(const A&);
    A& operator=(const A&);
};

#if 1
class B :public A{
public:
    B(int x, int y){
        this->y = y;
    }
	
	/*
    B(int x, int y) :A(x){
        this->y = y;
    }*/
    
	/*B createTempB(B b){
        B temp = b;
        return temp;
    }*/
    
    void show(){
        cout << y << endl;
    }
private:
    int y;
};
#endif 

int main(){
    //A a(1);
	B b(1, 10);
	B c=b;

    return 0;
}


