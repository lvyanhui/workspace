#include "CString.h"

int main(int argc, char** argv) {
	CString a="abc";
	CString b=a;
	CString c(a);
	CString d;
	d = a;

	std::cout << a.C_str() << std::endl;
	std::cout << b.C_str() << std::endl;
	std::cout << c.C_str() << std::endl;
	std::cout << d.C_str() << std::endl;

    char* p= NULL;
	CString e = p;
	std::cout << e.C_str() << std::endl;
}
