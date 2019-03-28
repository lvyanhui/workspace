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
	
	void test1(A& a);
	void test2(const A& a);
	void test3(A* y);
	void test4(std::shared_ptr<A> z);

private:
	B(const B&) = delete;
	B& operator =(const B& ) = delete;

private:
	std::shared_ptr<A> a;
	A* a1;
};

#endif

