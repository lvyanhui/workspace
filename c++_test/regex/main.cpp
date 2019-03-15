#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main()
{
	//regex_match匹配整个字符串
	regex reg1("\\w+day");
	string s1 = "saturday";
	string s2 = "saturday and sunday";
	smatch r1;
	smatch r2;
	cout << boolalpha << regex_match(s1, r1, reg1) << endl;
	cout << boolalpha << regex_match(s2, r2, reg1) << endl;
	cout << "s1匹配结果：" << r1.str() << endl;
	cout << "s2匹配结果：" << r2.str() << endl;
	cout << endl;

	//regex_match只返回第一个匹配结果
	smatch rr1;
	smatch rr2;
	cout << boolalpha << regex_search(s1, rr1, reg1) << endl;
	cout << "s1匹配结果：" << rr1.str() << endl;
	cout << boolalpha << regex_search(s2, rr2, reg1) << endl;
	cout << "s1匹配结果：" << rr2.str() << endl;
	cout << endl;


	//使用iterator返回多个匹配结果
	//结果要用->
	cout << "iterator结果：" << endl;
	sregex_iterator it(s2.begin(), s2.end(), reg1);
	sregex_iterator end;
	for(; it != end; ++it)
	{
		cout << it->str() << endl;
		//cout << *it << endl; 错误
	}

	cout << "token_iterator结果：" << endl;
	sregex_token_iterator tit(s2.begin(), s2.end(), reg1);
	sregex_token_iterator tend;
	for(; tit != tend; ++tit)
	{
		cout << tit->str() << endl;
		cout << *tit << endl;
	}

	//子表达式匹配
	regex reg2("(\\d{1,3}):(\\d{1,3}):(\\d{1,3}):(\\d{1,3})");
	string ip = "0:11:222:333";
	smatch m; 
	regex_match(ip, m, reg2);
	cout << "输出：str()" << endl;
	cout << m.str() << endl;
	cout << m.str(1) << endl;
	cout << m.str(2) << endl;
	cout << m.str(3) << endl;
	cout << m.str(4) << endl;

	cout << "输出：[i]" << endl;
	cout << m[0] << endl;
	cout << m[1] << endl;
	cout << m[2] << endl;
	cout << m[3] << endl;
	cout << m[4] << endl;

	//输出结果同上
	//regex_search(ip, m, str2);
	cout << endl;
	string ip2 = "0:11:222:333 4:55:66:7";
	sregex_iterator ip_it(ip2.begin(), ip2.end(), reg2);
	sregex_iterator ip_end;
	for(; ip_it != ip_end; ++ip_it)
	{
		cout << ip_it->str() << endl;
		cout << ip_it->str(1) << endl;
		cout << ip_it->str(2) << endl;
		cout << ip_it->str(3) << endl;
		cout << ip_it->str(4) << endl;
	}

	return 0;

}
