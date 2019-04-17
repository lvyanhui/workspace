#include <iostream>

template <typename T>
class Singleton {
	public:
		//支持一个参数的构造函数
		template<typename... Args>
			static T* Instance(Args&&... args) {
				if(m_pInstance==nullptr)
					m_pInstance = new T(std::forward<Args>(args)...);

				return m_pInstance;
			}
		
		static T* GetInstance() {
			if(m_pInstance == nullptr)
				throw std::logic_error("the instance is not init, please initialize the instance first.");

			return m_pInstance;
		}

		static void DestroyInstance() {
			delete m_pInstance;
			m_pInstance = nullptr;
		}

	private:
		Singleton(void);
		virtual ~Singleton(void);
		Singleton(const Singleton& );
		Singleton& operator = (const Singleton&);
	
	private:
		static T* m_pInstance;
};

template <typename T> T* Singleton<T>::m_pInstance = nullptr;

class A {
public:
	A(){}	
	void done(){std::cout << "A do" << std::endl;}
};

struct B {
	B(int x){}	
public:
	void done(){std::cout << "B do" << std::endl;}
};

struct C{
	C(int x, double y){}	
public:
	void done(){std::cout << "C do" << std::endl;}
};

int main(){
	Singleton<A>::Instance();
	Singleton<B>::Instance(1);
	Singleton<C>::Instance(1, 3.14);
	
	A* ax = Singleton<A>::GetInstance();
	ax->done();
	B* bx = Singleton<B>::GetInstance();
	bx->done();
	C* cx = Singleton<C>::GetInstance();
	cx->done();

	Singleton<A>::DestroyInstance();
	Singleton<B>::DestroyInstance();
	Singleton<C>::DestroyInstance();

}
