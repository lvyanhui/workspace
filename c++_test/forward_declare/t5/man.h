#pragma once
//#include "person.h"

#include <iostream>
#include <memory>
class Person;

class Man
{
	public:
		Man(std::shared_ptr<Person> child);
		~Man(void);

		void test();
	private:
		//Person* child;
		std::shared_ptr<Person> child;
};
