#include <iostream>
#include "man.h"
#include "person.h"

int main() {
	std::shared_ptr<Person> child = std::make_shared<Person>();
	
	Man m(child);
	m.test();

	//delete child;
	return 0;
}
