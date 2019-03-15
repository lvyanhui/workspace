#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {

	auto f = []()->int{return 1;};
	cout << "value : " << f() << endl;

	std::cout << "value : " << [](int a)->int{return a;}(3) << endl;
}
