#pragma once
#include "person.h"
class Man : public Person
{
	public:
		Man(void);
		~Man(void);
	private:
		Person child;
};
