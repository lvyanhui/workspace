#include <iostream>

typedef int(*Fun)(int a, int b);

int sum(int a, int b) {
	return a+b;
}

int min(int a, int b) {
	return a-b;
}

int main(int argc, char** argv) {
	Fun fun = sum;
	int result = fun(3,4);
    std::cout << result << std::endl;
	
	fun = min;
	result = fun(3,4);
    std::cout << result << std::endl;
}
