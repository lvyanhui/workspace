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

struct A {
	A(const std::string&){ std::cout << "lvalue" << std::endl;}	
	A(std::string&& x){std::cout << "rvalue" << std::endl;}
};

struct B {
	B(const std::string&){std::cout << "lvalue" << std::endl;}	
	B(std::string&& x){std::cout << "rvalue" << std::endl;}	
};

struct C{
	C(int x, double y){}	
public:
	void Fun(){std::cout << "C test" << std::endl;}
};

int main(){
	std::string str = "sin";
	Singleton<A>::Instance(str);
	Singleton<B>::Instance(std::move(str));
	Singleton<C>::Instance(1, 3.14);
	Singleton<C>::GetInstance()->Fun();

	Singleton<A>::DestroyInstance();
	Singleton<B>::DestroyInstance();
	Singleton<C>::DestroyInstance();
}
