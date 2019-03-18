#ifndef _CSTRING_H_
#define _CSTRING_H_

#include <string.h>
#include <iostream>

class CString{
	public:
		CString();
		CString(const char* p);
		~CString();
		CString(const CString& str);
		CString& operator=(const CString& str);
	
		int getLength() const { return length_;}
		char* C_str() {return data_;}
	private:
		char* data_;
		int length_;
};

CString::CString():length_(0) {
	//data_ = new char(0);
	data_ = new char[1];
	data_[0]='\0';
}

/*CString::CString(const char* p) {
	int length = strlen(p);	//strlen 不包含'\0'
	data_ = new char[length+1];	 
	strcpy(data_, p);       //strcpy包含'\0'
	this->length_ = length;
}*/

CString::CString(const char* p) {
	if(p == NULL){
		data_ = new char[1];
		data_[0]='\0';
	} else {
		int length = strlen(p);	//strlen 不包含'\0'
		data_ = new char[length+1];	 
		strcpy(data_, p);       //strcpy包含'\0'
		this->length_ = length;
	}
}

CString::~CString(){
	delete[] data_;
	data_ = NULL;
	length_ = 0;
}

CString::CString(const CString& str) {
	//if(this == &str)
	//    return;
	//else {
	//int length = str.getLength();
	int length = str.length_; //访问限制标号是针对类而不是针对一个类的不同对象，只要同属一个类就可以不用区分同一个类的不同对象。因为CExample(const CExample& RightSides) 是类的成员函数，所以有权限访问私有数据成员。如果是在main函数中直接RightSides.nSize，那肯定就会报错了，不能访问，因为这是在类外不能访问私有数据成员。一个类的成员函数可以访问这个类的私有数据成员，我们要理解这个对类的访问限制，而不是针对对象。

	//	delete data_;
	data_ = new char[length+1];
	strcpy(data_, str.data_);
	//} 拷贝构造，那么这个对象一定不存在，所以不可能是自拷贝，也不需要释放data_
}

CString& CString::operator=(const CString& str) {
	if(this == &str)	
		return *this;

	if(data_ != NULL)
		delete[] data_;
	data_ = new char[str.length_+1];
	strcpy(data_, str.data_);
	return *this;
}

#endif
