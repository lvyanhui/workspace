## 1.  父类和子类的初始化、销毁顺序

### 1.1 使用子类对象

```
初始化时，先初始化父类，再初始化子类；
销毁时，先销毁子类，再销毁父类；
```

**示例**

```
#include <iostream>

using namespace std;

class Base {
	public:
		Base(){cout<< "base " << endl;}
		//virtual ~Base(){cout << "destroy base" << endl;}
		~Base(){cout << "destroy base" << endl;}	
};

class Derive: public Base {
	public:
		Derive(){cout<< "derive " << endl;}
		~Derive(){cout << "destroy derive" << endl;}	
};

int main(int argc, char** argv) {
    Derive d;
}
```

> **执行结果**

```
lyh@ubuntu:~/workspace/workspace/c++_test/base$ ./main 
base 
derive 
destroy derive
destroy base
```

### 1.2 使用子类的指针 

```
初始化时，先初始化父类，再初始化子类;
销毁时，先销毁子类，再销毁父类；
```

**示例**

```
#include <iostream>

using namespace std;

class Base {
	public:
		Base(){cout<< "base " << endl;}
		//virtual ~Base(){cout << "destroy base" << endl;}
		~Base(){cout << "destroy base" << endl;}
	
};

class Derive: public Base {
	public:
		Derive(){cout<< "derive " << endl;}
		~Derive(){cout << "destroy derive" << endl;}
	
};

int main(int argc, char** argv) {
    Derive* d = new Derive();
	delete d;
}
```

>**执行结果**

```
lyh@ubuntu:~/workspace/workspace/c++_test/base$ ./main 
base 
derive 
destroy derive
destroy base
```

### 1.3 使用父类的指针

```
初始化时，先初始化父类，再初始化子类;
销毁时，先销毁子类，再销毁父类；
```

**示例1**

```
#include <iostream>

using namespace std;

class Base {
	public:
		Base(){cout<< "base " << endl;}
		//virtual ~Base(){cout << "destroy base" << endl;}
		~Base(){cout << "destroy base" << endl;}
	
};

class Derive: public Base {
	public:
		Derive(){cout<< "derive " << endl;}
		~Derive(){cout << "destroy derive" << endl;}
	
};

int main(int argc, char** argv) {
    Base* b = new Derive();
	delete b;
}
```

> **执行结果**

```
lyh@ubuntu:~/workspace/workspace/c++_test/base$ ./main 
base 
derive 
destroy derive
```

***我们发现，父类的指针没有被调用，原因是父类的析构函数不是虚函数，详细的原因我还待学习***

**示例2**

```
#include <iostream>

using namespace std;

class Base {
	public:
		Base(){cout<< "base " << endl;}
		virtual ~Base(){cout << "destroy base" << endl;}
};

class Derive: public Base {
	public:
		Derive(){cout<< "derive " << endl;}
		~Derive(){cout << "destroy derive" << endl;}
	
};

int main(int argc, char** argv) {
    Base* b = new Derive();
	delete b;
}
```

> **执行结果**:***父类被析构***

```
lyh@ubuntu:~/workspace/workspace/c++_test/base$ ./main 
base 
derive 
destroy derive
destroy base
```





