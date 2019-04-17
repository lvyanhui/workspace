#include <iostream>
using namespace std;

class Singleton
{
	public:
		static Singleton *GetInstance()
		{
			if (m_Instance == NULL)
			{
				m_Instance = new Singleton();
				cout<<"get Singleton instance success"<<endl;
			}
			return m_Instance;
		}

	private:
		Singleton(){cout<<"Singleton construction"<<endl;}
		static Singleton *m_Instance;

		// This is important
		class GC // 垃圾回收类
		{
			public:
				GC()
				{
					cout<<"GC construction"<<endl;
				}
				~GC()
				{
					cout<<"GC destruction"<<endl;
					// We can destory all the resouce here, eg:db connector, file handle and so on
					if (m_Instance != NULL)
					{
						delete m_Instance;
						m_Instance = NULL;
						cout<<"Singleton destruction"<<endl;
						//system("pause");//不暂停程序会自动退出，看不清输出信息
					}
				}
		};
		static GC gc;  //垃圾回收类的静态成员

};

Singleton *Singleton::m_Instance = NULL;
Singleton::GC Singleton::gc; //类的静态成员需要类外部初始化，这一点很重要，否则程序运行连GC的构造都不会进入，何谈自动析构
int main(int argc, char *argv[])
{
	Singleton *singletonObj = Singleton::GetInstance();
	return 0;
}
