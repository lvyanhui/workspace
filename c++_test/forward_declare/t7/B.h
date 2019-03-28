#ifndef _B_H_
#define _B_H_

#include <iostream>
#include <memory>

class A;

class B{

public:
	B();
	~B();

	void test();

private:
	B(const B&) = delete;
	B& operator =(const B& ) = delete;

private:
	std::shared_ptr<A> a;
};

#endif

