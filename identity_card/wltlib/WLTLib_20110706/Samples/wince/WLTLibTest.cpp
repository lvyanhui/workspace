// WLTLibTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <windows.h>
#include <commctrl.h>

#include "../../include/WLTLib.h"
#include <iostream>
#include <fstream>
#pragma comment(lib, "../../lib/arm/wince/wltlib.lib")
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

char cLic[]= "0501-20110511-0123456789";//"0501-20101105-0001207685";

void GetCurrentDirectory(char *pBuf)
{
 GetModuleFileName(NULL,(wchar_t*)pBuf,sizeof(pBuf)/sizeof(wchar_t));
}

int _tmain(int argc, _TCHAR* argv[])
{
char *pLic = cLic;
char pBuf[256];

	char version[128];
	CV_VersionInfo(version);
	cout<<version<<endl;
	ifstream inbase("\\Storage Card\\WLTTestData\\base.dat", ios_base::binary);
	inbase.seekg(0, ios::end);
	int lengthbase = inbase.tellg();
	inbase.seekg(0, ios::beg);
	int * pBaseData = new int[lengthbase];
	inbase.read((char *)pBaseData, lengthbase);

	GetCurrentDirectory(pBuf);

	cout<<"Working Dir  = "<<pBuf<<endl;

	int err = CV_Initialize((const char*)pLic, pBaseData);	
	delete []pBaseData;
	if(err != CV_ERR_NONE)
	{
		cout<<"CV_Initialize errno = "<<err<<endl;
	}
	else
	{
		int ret = Decode2BmpFile("\\Storage Card\\WLTTestData\\sample.wlt", "\\Storage Card\\WLTTestData\\sample_wince.bmp");
	}
	CV_Finalize();
	
	return 0;
}

