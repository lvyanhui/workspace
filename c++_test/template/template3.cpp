#include <iostream>

using namespace std;

template <class T>
class Compare{

public:
	Compare(T base){
		base_ = base;
	}

	T Min(T x) {
		return x<base_?x:base_;
	}

private:
	T base_;

};


int main(int argc, char** argv) {

	int a=50, b =60;
	Compare<int > cmp(40);
	cout << "min integer: " << cmp.Min(a) << endl;




}
