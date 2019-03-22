## 1.  类的初始化、销毁顺序

### 1.1 初始化、析构顺序如下

```
初始化：
父类的成员变量
父类的构造函数
子类的成员变量
子类的构造函数

析构：
子类的构造函数
子类的成员变量
父类的构造函数
父类的成员变量
```

**示例1**

```
#include <iostream>

using namespace std;

class A {
	public:
		A(){cout<< "A " << endl;}
		~A(){cout << "destroy A" << endl;}
};

class B {
	public:
		B(){cout<< "B " << endl;}
		~B(){cout << "destroy B" << endl;}
};

class Base {
	public:
		Base(){cout<< "base " << endl;}
		virtual ~Base(){cout << "destroy base" << endl;}
	
	private:
		A a;
};

class Derive: public Base {
	public:
		Derive(){cout<< "derive " << endl;}
		~Derive(){cout << "destroy derive" << endl;}
	
	private:
	    B b;
};

int main(int argc, char** argv) {
	Base* b = new Derive();
	delete b;
}

```

> *执行结果*

```
lyh@ubuntu:~/workspace/workspace/c++_test/base$ ./main 
A 
base 
B 
derive 
destroy derive
destroy B
destroy base
destroy A

```

**总结**：

	析构的顺序与构造的顺序正好相反；
	类的析构函数要早于成员变量的析构函数：也就是说类析构时成员变量都在；如果某个程是使用成员变量启动的，那么就可以在析构函数中调用通过成员变量的成员函数结束线程运行；



## 1.2 带有线程的类的析构

**示例1**

```
#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>

using namespace std;

class A {
	public:
		A() {
			need_to_terminate_ = false;
			cout<< "A " << endl;
		}
		
		~A(){
			if(thread_.joinable())
				thread_.join();

			cout << "destroy A" << endl;
		}
		
		void start() {
			cout << "A start" << endl;
			thread_ = std::thread(&A::run, this);
		}
		void stop() {
			cout << "A stop" << endl;
			need_to_terminate_ = true;
		}
		void run() {
			cout << "A run" << endl;
			while(!need_to_terminate_) {
				std::this_thread::sleep_for(std::chrono::milliseconds(200));
			}
			cout << "A run exit" << endl;
		}
	
	private:
		std::thread thread_;
		std::atomic<bool> need_to_terminate_;
};

class Base {
	public:
		Base(){
			cout<< "base " << endl;
		    a.start();
		}

		~Base() {
			a.stop();
			cout << "destroy base" << endl;
		}
	
	private:
		A a;
};

int main(int argc, char** argv) {
	Base* b = new Base();
    std::this_thread::sleep_for(std::chrono::seconds(1));

	delete b;
}

```

> 执行结果

```
lyh@ubuntu:~/workspace/workspace/c++_test/base$ ./main 
A 
base 
A start
A run
A stop
destroy base
A run exit
destroy A

```

