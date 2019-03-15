#include <iostream>
#include "man.h"
#include "person.h"

int main() {
	Person* child = new Person();
	Man m(child);
	m.test();

	delete child;
	return 0;
}
