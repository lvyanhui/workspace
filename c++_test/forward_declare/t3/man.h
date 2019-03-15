#pragma once
//#include "person.h"
class Person;

class Man
{
	public:
		Man(Person* child);
		~Man(void);

		void test();
	private:
		Person* child;
};
