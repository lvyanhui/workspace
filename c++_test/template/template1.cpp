#include <iostream>
#include <string>

using namespace std;


template <typename T>
T Min(T x, T y) {
	return (x<y?x:y);
}

int main(int argc, char** argv) {

	int n1 = 3;
	int n2 = 4;
	cout<<"min integer: " << Min(n1, n2) << endl;
	
    double d1 = 0.3;
	double d2 = 0.4;

	cout<<"min double: " << Min(d1, d2) << endl;

	return 0;	
}
