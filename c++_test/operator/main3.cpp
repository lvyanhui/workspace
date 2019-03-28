/*************************************************************************
 > File Name: main3.cpp
 > Author: test
 */

#include <iostream>

template <typename T>
class Plus {
	public:
		T operator() (const T & x, const T& y) const {
			return x+y;
		}
};

int main(int argc, char** argv) {
	Plus<int> plus;

	std::cout << plus(3, 10) << std::endl;
}



