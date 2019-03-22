## 1.  类的初始化、销毁顺序

### 1.1 如果使用的是类对象

```
在初始化时，默认调用构造函数；
在超出作用域时，默认调用析构函数；
```

**示例1**

```
#include <iostream>

using namespace std;

class Base {
	public:
		Base(){cout<< "base " << endl;}
		~Base(){cout << "destroy base" << endl;}	
};

int main(int argc, char** argv) {
	Base b;
}
```

> *执行结果*

```
lyh@ubuntu:~/workspace/workspace/c++_test/base$ ./main 
base 
destroy base
```



### 1.2 如果使用的是类的指针

```
需要显示调用delete来析构
```

**示例1：**没有调用delete

```
#include <iostream>

using namespace std;

class Base {
	public:
		Base(){cout<< "base " << endl;}
		~Base(){cout << "destroy base" << endl;}	
};

int main(int argc, char** argv) {
	Base* b = new Base();
}
```

> **执行结果**： 只调用了构造函数，没有调用析构函数；

```
lyh@ubuntu:~/workspace/workspace/c++_test/base$ ./main 
base 
```

**示例2：** 调用了delete

```
#include <iostream>

using namespace std;

class Base {
	public:
		Base(){cout<< "base " << endl;}
		~Base(){cout << "destroy base" << endl;}
	
};

int main(int argc, char** argv) {
	Base* b = new Base();
	delete b;
}
```

> **执行结果**： 只调用了构造函数，没有调用析构函数；

```
lyh@ubuntu:~/workspace/workspace/c++_test/base$ ./main 
base 
destroy base 
```



