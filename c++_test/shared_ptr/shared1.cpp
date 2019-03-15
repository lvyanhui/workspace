#include <iostream>
#include <string>
#include <memory>

using namespace std;

class MyString {
public:
	MyString(const char* text):m_text(text) {
		cout << "Constructed(" << text << ")!" << endl;
	}
	
	~MyString() {
		cout << "Destructed(" << m_text << ")!" << endl;
	}

	void output() {
		cout << m_text << endl;
	}

private:
	string m_text;
};

int main() {
	shared_ptr<MyString > p1;
	shared_ptr<MyString > p2 = make_shared<MyString>("Hello SmartPointer");

	cout << "ps_count:" << p2.use_count() << endl;
	cout << "p1get():" << p1.get() << endl;
	cout << "p2get():" << p2.get() << endl;
	
	p1 = p2;
	cout << "ps_count:" << p2.use_count() << endl;
	cout << "p1get():" << p1.get() << endl;
	cout << "p2get():" << p2.get() << endl;
	
	p1->output();
	p2->output();

	shared_ptr<MyString > p3(new MyString("new  Mystring"));

	return 0;
}

