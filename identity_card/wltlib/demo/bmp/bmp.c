#include <stdio.h>            
#include <time.h>
#include <iconv.h>
#include <stdlib.h>
#include <string.h>
#include <termio.h>
#include <fcntl.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>   
#include <sys/ioctl.h>

#include "WLTLib.h"
#include <iostream>
#include <fstream>
using namespace std;



const char* liccode = "0503-20120903-0000409247";
const char* datpath = "./base.dat";
const char* wltpath = "./zp.wlt";
int Decode2BmpFile(const char * wltFile, const char * bmpFile);
int getbmp();

int main()
{
  
   getbmp();

}
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
	if(ret==1)
       cout<<"Decode sucess "<<endl;
	else
        cout<<"Decode erro "<<endl;

	ofstream out(bmpFile, ios_base::binary);
	out.write((char *)pOutBuffer, outlength);

	delete []pData;
	delete []pOutBuffer;

	return ret;
}

int getbmp()
{
    const char* outputBmp = "./zp.bmp" ;
    int ret =-1;
    ifstream inbase(datpath, ios_base::binary);
	inbase.seekg(0, ios::end);
	int lengthbase = inbase.tellg();
	inbase.seekg(0, ios::beg);
	int * pBaseData = new int[lengthbase];
	inbase.read((char *)pBaseData, lengthbase);
	int err = CV_Initialize(liccode, pBaseData);	
	delete []pBaseData;

    
	if(err != CV_ERR_NONE)
	{
		cout<<"CV_Initialize errno = "<<err<<endl;
        return -1;
	}
	else
	{
		ret = Decode2BmpFile(wltpath, outputBmp);
	}
	CV_Finalize();
    return ret;
}

