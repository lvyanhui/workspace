#include <iostream> 
#include <string.h> 
using namespace std; 
int gbk_strlen(const char* str)
{ 
	const char* p = str; //p用于后面遍历 
	while(*p) //若是结束符0，则结束循环 
	{ 
		if(*p < 0 && (*(p+1)<0 || *(p+1) < 63)) //中文汉字情况 
		{ 
			str++; //str移动一位，p移动移动2位，因此长度加1 
			p += 2; 
		} else { 
			p++; //str不动，p移动一位，长度加1 
		} 
	} 
	return p-str; //返回地址之差 
} 

static int GetUtf8LetterNumber(const char *s)
{
	int i = 0, j = 0;
	while (s[i])
	{
		if ((s[i] & 0xc0) != 0x80) j++;
		i++;
	}
	return j;
}

void remove_end_punc(char* str) {
	
}

int main(){
	char str[] = "abc你好123中国456"; 
	cout<<gbk_strlen(str)<<endl; 
	cout<<GetUtf8LetterNumber(str)<<endl; 
}
