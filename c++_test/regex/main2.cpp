#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main()
{
	string str = "{this is {right}}{that is {right}};";
	//regex sep("\\wh", regex::icase);
	regex sep("\\}\\{", regex::icase);
	sregex_token_iterator endite;
	sregex_token_iterator begite(str.begin(), str.end(), sep, -1);
	while (begite != endite) {
		cout <<*begite++ << endl;
		cout << "}{" << endl;
	}
}
