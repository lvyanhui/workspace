###  前向声明

#### 1.类成员函数是指针

*A.h*

```
#ifndef _A_H_
#define _A_H_

class A{
public:
	A();
	~A();
	void test();
};
#endif
```

*A.cpp*

```
#include "A.h"
#include <iostream>
using namespace std;

A::A() {
    cout << "create A" << endl;
}
A::~A() {
    cout << "destroy A" << endl;
}
void A::test() {
    cout << "A go..." << endl;
}
```

*B.h*

```
#ifndef _B_H_
#define _B_H_

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
	A* a;
};
#endif
```

*B.cpp*

```
#include "B.h"

#include "A.h"
#include <iostream>

using namespace std;

B::B() {
    cout << "create B" << endl;
	a = new A();
}
B::~B() {
    cout << "destroy B" << endl;
    delete a;
}
void B::test() {
    cout << "B test" << endl;
	a->test();
}
```

*main.cpp*

```
#include "B.h"

int main(int argc, char** argv) {
	B b;
	b.test();
}

```

**编译**

```
g++ -o main A.cpp B.cpp main.cpp 
```

**执行结果**

```
lyh@ubuntu:~/workspace/workspace/c++_test/forward_declare/t7$ ./main 
create B
create A
B test
A test
destroy B
destroy A
```

**要点解析**

* "B.h" 中没有引入"A.h",只是定义了class A；

* 在B.cpp中使用了类A的实现，a->test(), 因此，添加了#include "A.h"；

* main.cpp中只引用了B.h,他不需要引用A.h

  这样做的好处在于当A.h改变时，只需要编译B.cpp；如果直接在B.h中添加#include "A.h"，那么所有引用了B.h头文件的文件，都需要重新编译；避免了展开负担；

**总结**

```
1. 类A只是B类使用，所以不需要main.cpp知道类A，因此，main.cpp中只包含B.h
2. 因为类B中有指针，所以不能使用编译器自动生成的拷贝构造函数和赋值函数，这里我不想编写，或者说不会使用，因此，将拷贝构造函数和赋值函数屏蔽；使用delete屏蔽是c++11的特性；
3. 类B的成员函数是A* a； 所以类B的头文件不需要include "A.h"；如果其它文件需要包含”B.h“，就不会被动的引入"A.h", 降低了编译时间；这个在大规模程序中是很重要的；因此，在设计时，需要考虑如果类的成员变量只是本类需要，而不需要调用此类的其它文件需要，那么最好声明成指针；在做成员函数参数时，也要使用指针或者引用类型；
4. 如果指针是共享指针，也可以正常编译；
```



#### 2.指针使用共享指针

*B.h*

```
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
```

B.cpp

```
#include "B.h"
#include "A.h"
#include <iostream>

using namespace std;
B::B() {
    cout << "create B" << endl;
	a = std::make_shared<A>();
}
B::~B() {
    cout << "destroy B" << endl;
}
void B::test() {
    cout << "B test" << endl;
	a->test();
}
```

**其它文件同上**；

**执行结果**

```
lyh@ubuntu:~/workspace/workspace/c++_test/forward_declare/t7$ ./main 
create B
create A
B test
A test
destroy B
destroy A
```

#### 3. 其它可以使用前向声明的情况

*B.h*

```
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

```

B.cpp

```
#include "B.h"
#include "A.h"
#include <iostream>
using namespace std;

B::B() {
    cout << "create B" << endl;
	a = std::make_shared<A>();
}
B::~B() {
    cout << "destroy B" << endl;
}
void B::test() {
    cout << "B test" << endl;
	a->test();
}
void B::test1(A& a) {
}
void B::test2(const A& a) {
}
void B::test3(A* y){
}
void B::test4(std::shared_ptr<A> z) {
}
```

