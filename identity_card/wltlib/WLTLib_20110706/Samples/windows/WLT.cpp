// WLT.cpp : Defines the entry point for the console application.
//

#include "WLTLib.h"
#include <iostream>
#include <fstream>
#pragma comment(lib, "wltlib.lib")
using namespace std;

int Decode2BmpFile(const char * wltFile, const char * bmpFile)
{
	ifstream in(wltFile, ios_base::binary);
	in.seekg(0, ios::end);
	int length = in.tellg();
	in.seekg(0, ios::beg);
	unsigned char * pData = new unsigned char [length];
	in.read((char *)pData, length);
	
	unsigned char * pOutBuffer = new unsigned char [126 * 102 * 3 + 1024];
	int outlength;
	int ret = CV_Decode(pData, length, pOutBuffer, CV_FORMAT_BMP, &outlength);
	cout<<"Decode return "<<ret<<endl;
	ofstream out(bmpFile, ios_base::binary);
	out.write((char *)pOutBuffer, outlength);

	delete []pData;
	delete []pOutBuffer;

	return ret;
}

int main(int argc, char* argv[])
{
	/*if (argc != 5)
	{
		cout<<"Usage: WLT.exe wltFile bmpFile baseFile license"<<endl;
		return 1;
	}*/
	char version[128];
	CV_VersionInfo(version);
	cout<<version<<endl;
	ifstream inbase(argv[3], ios_base::binary);
	inbase.seekg(0, ios::end);
	int lengthbase = inbase.tellg();
	inbase.seekg(0, ios::beg);
	int * pBaseData = new int[lengthbase];
	inbase.read((char *)pBaseData, lengthbase);


	int err = CV_Initialize(argv[4], pBaseData);	
	delete []pBaseData;
	if(err != CV_ERR_NONE)
	{
		cout<<"CV_Initialize errno = "<<err<<endl;
	}
	else
	{
		int ret = Decode2BmpFile(argv[1], argv[2]);
	}
	CV_Finalize();
	
	return 0;
}

