#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	
	int num;
	auto f = [&num]()->int{return num;};
	num = 4;
	cout << "value : " << f() << endl;


	auto f1 = [&](int num2)->int{return num2;};
	num = 8;
	cout << "value : " << f1(num) << endl;


	std::cout << "value : " << [](int a)->int{return a;}(3) << endl;
}
