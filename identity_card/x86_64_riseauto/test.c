#include "libtermb.h"
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <memory.h>
#include <malloc.h>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <string.h>
#include <iconv.h>



#define PRINT_LOG	1

// open 成功返回 0 ，失败返回 -1 ；
int GHC_InitUSB() {
	int iResult = 0;
	char UsbDevice[] = "/dev/ttyUSB0";

	iResult = InitComm(UsbDevice);
	if (iResult != 1) {
		if(PRINT_LOG)printf("InitComm error:%d\n", iResult);
		CloseComm();
		iResult =  -1;
	} else
		iResult = 0;

	return iResult;
}

//读取模块SAMID
int GHC_ReadSAMIDStr(char* SAMIDStr) {
	int iResult = 0;
	char SAMID[50];

	memset(SAMID, 0x00, sizeof(SAMID));
	iResult = GetSamdId(SAMID);
	if(iResult == 1) {
		memcpy(SAMIDStr, SAMID, strlen(SAMID));
		iResult = 0;
	} else {
		iResult = -1;
	}
	return iResult;
}


//读取身份证基本信息
int GHC_ReadBaseMsg(char* szTxt, char* szBmp) {
	char szWlt[2048] = {0};

	if(FindCardCmd() != 0x9f) {
		if(PRINT_LOG)printf("find card fail ! \n");
		return -101;	//find card fail
	}

	if(SelCardCmd() != 0x90) {
		if(PRINT_LOG)printf("find card fail ! \n");
		return -102;	//select card fail
	}

	if(ReadCard(szTxt, szWlt, szBmp) != 1) {
		if(PRINT_LOG)printf("ReadCard error\n");
		return -103;
	}

	return 0;
}


//读取身份证基本信息【支持循环调用】
int GHC_ReadBaseMsg_loop(char* szTxt, char* szBmp) {
	char szWlt[2048] = {0};

	if(ReadCard(szTxt, szWlt, szBmp) != 1) {
		if(FindCardCmd() != 0x9f) {
			if(PRINT_LOG)printf("find card fail ! \n");
			return -101;	//find card fail
		}

		if(SelCardCmd() != 0x90) {
			if(PRINT_LOG)printf("find card fail ! \n");
			return -102;	//select card fail
		}

		if(ReadCard(szTxt, szWlt, szBmp) != 1) {
			if(PRINT_LOG)printf("ReadCard error\n");
			return -103;
		}
	}
	return 0;
}

//读取身份证信息，带指纹
int GHC_ReadFPMsg(char* szTxt, char* szBmp, char* szFinger, int *iFingerLen) {
	char szWlt[2048] = {0};

	if(FindCardCmd() != 0x9f) {
		if(PRINT_LOG)printf("find card fail ! \n");
		return -101;	//find card fail
	}

	if(SelCardCmd() != 0x90) {
		if(PRINT_LOG)printf("find card fail ! \n");
		return -102;	//select card fail
	}

	if(ReadCardExt(szTxt, szWlt, szBmp) != 1) {
		if(PRINT_LOG)printf("ReadCard error\n");
		return -103;
	}

	*iFingerLen = GetFingerData(szFinger);
	return 0;
}

//读取身份证信息，带指纹【支持循环调用】
int GHC_ReadFPMsg_loop(char* szTxt, char* szBmp, char* szFinger, int *iFingerLen) {
	char szWlt[2048] = {0x00};

	if(ReadCardExt(szTxt, szWlt, szBmp) != 1) {
		if(FindCardCmd() != 0x9f) {
			if(PRINT_LOG)printf("find card fail ! \n");
			return -101;	//find card fail
		}

		if(SelCardCmd() != 0x90) {
			if(PRINT_LOG)printf("find card fail ! \n");
			return -102;	//select card fail
		}

		if(ReadCardExt(szTxt, szWlt, szBmp) != 1) {
			if(PRINT_LOG)printf("ReadCard error\n");
			return -103;
		}
	}

	*iFingerLen = GetFingerData(szFinger);
	return 0;
}


//关闭
void GHC_CloseUSB() {
	CloseComm();
}


int code_convert(char *from_charset,char *to_charset,char *inbuf,int inlen,char *outbuf,int outlen) {
	iconv_t cd;
	int rc;
	char **pin = &inbuf;
	char **pout = &outbuf;

	cd = iconv_open(to_charset,from_charset);
	if (cd==0) return -1;
	memset(outbuf,0,outlen);
	if (iconv(cd,pin,&inlen,pout,&outlen)==-1) return -1;
	iconv_close(cd);
	return 0;
}

//UNICODE码转为GB2312码
int u2g(char *inbuf,int inlen,char *outbuf,int outlen) {
	return code_convert("utf-8","gb2312",inbuf,inlen,outbuf,outlen);
}
//GB2312码转为UNICODE码
int g2u(char *inbuf,size_t inlen,char *outbuf,size_t outlen) {
	return code_convert("gb2312","utf-8",inbuf,inlen,outbuf,outlen);
}


//保存图片到工作目录
void SaveBMP(char* dataBMP, int DataLen)
{
	char fullpath[256] = {0x00};
	char *dir = getcwd(fullpath, sizeof(fullpath));
	
	strcat(fullpath, "/headphoto.bmp");
	
	int fd = open(fullpath, O_RDWR|O_CREAT);
	
	if(fd != -1){
		ftruncate(fd,0);//清理
		lseek(fd,0,SEEK_SET);//重新设置文件偏移量
		write(fd, dataBMP, DataLen);
		close(fd);
	}
}




int main() {
	int iResult = 0;
	char SAMIDStr[64];

	char szTxt_GB2312[500] = {0x00};
	char szTxt_UTF[1024] = {0x00};
	char szBmp[38862] = {0x00};
	char szFinger[1024] = {0x00};
	int iFingerLen = 0;

	if(GHC_InitUSB() == 0) {
		/** 读取模块SAMID 开始**/
		memset(SAMIDStr, 0x00, sizeof(SAMIDStr));
		if(GHC_ReadSAMIDStr(SAMIDStr) == 0)
			if(PRINT_LOG)printf("SAMID = [%s] .\n", SAMIDStr);
			else {
				if(PRINT_LOG)printf("Get SAMID error .\n");
			}
		/** 读取模块SAMID 结束**/


		/** 读取身份证基本信息 开始**/
		if(GHC_ReadBaseMsg(szTxt_GB2312, szBmp) == 0) {
			//保存bmp
			SaveBMP(szBmp, sizeof(szBmp));
			
			if(PRINT_LOG)printf("szTxt_GB2312 is: %s\n", szTxt_GB2312);	
			//转码
			iResult = g2u(szTxt_GB2312, strlen(szTxt_GB2312), szTxt_UTF, sizeof(szTxt_UTF));
			if(PRINT_LOG)printf("szTxt_UTF is: %s \n", szTxt_UTF);
			
		} else {
			if(PRINT_LOG)printf("Read IDCard Fail ! .\n");
		}
		/** 读取身份证基本信息 结束**/

	} else {
		if(PRINT_LOG)printf("open usb error!\n");
	}


	CloseComm();
	return iResult;
}


