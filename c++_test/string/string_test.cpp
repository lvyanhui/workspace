#include <iostream>
#include <cstring>
using namespace std;

class String  
{
	public:
		String(const char *str);
		String(const String &other);
		void operator=(const String &other);
		~String(void); 
	//private:
	public:
		char *m_data;
};

String::String(const char *str)
{
	cout << "自定义构造函数" << endl;
	if (str == NULL)
	{
		m_data = new char[1];
		*m_data = '\0';
	}
	else
	{
		int length = strlen(str);
		m_data = new char[length + 1];
		strcpy(m_data, str);
	}
}

String::String(const String &other)
{
	cout << "自定义拷贝构造函数" << endl;
	int length = strlen(other.m_data);
	m_data = new char[length + 1];
	strcpy(m_data, other.m_data);
}

void String::operator=(const String &other)
{
	cout << "自定义赋值函数" << endl; 

	if (this == &other)
	{
		//return *this;
	}
	else
	{
		delete [] m_data;
		int length = strlen(other.m_data);
		m_data = new char[length + 1];
		strcpy(m_data, other.m_data);
		//return *this;
	}
}
/* //返回值为String& 是为了级联，如（a=b=c;）
String & String::operator=(const String &other)
{
	cout << "自定义赋值函数" << endl; 

	if (this == &other)
	{
		return *this;
	}
	else
	{
		delete [] m_data;
		int length = strlen(other.m_data);
		m_data = new char[length + 1];
		strcpy(m_data, other.m_data);
		return *this;
	}
}
*/
String::~String(void)
{
	cout << "自定义析构函数" << endl; 
	delete [] m_data;
}
int main()
{
	cout << "a(\"abc\")" << endl;
	String a("abc");

	cout << "b(\"cde\")" << endl;
	String b("cde");

	cout << " d = a" << endl;
	String d = a;

	cout << "c(b)" << endl;
	String c(b);

	cout << "c = a" << endl;
	c = a;

	cout << "a: " << a.m_data << endl;
	cout << "c: " << c.m_data << endl;

	cout << endl;
}
