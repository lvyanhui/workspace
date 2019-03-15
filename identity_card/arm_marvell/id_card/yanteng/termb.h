#ifndef __TERMB_H
#define __TERMB_H

#ifdef __cplusplus
extern "C"
{
#endif

//函数功能：初始化端口
//参数：Port表示端口号
//返回值：搜索成功则返回端口号，否则返回0
int  InitComm(int Port);

//函数功能：自动搜索，初始化端口
//返回值：搜索成功则返回端口号，否则返回0
int  InitCommExt();

//函数功能：关闭端口
//返回值：1表示关闭端口成功，其他值表示错误
int  CloseComm();

//函数功能：卡认证，本函数用于读卡器和卡片之间的合法身份确认
//返回值：1表示卡片正确放置，其他表示未放卡或卡片放置不正确
int  Authenticate();

//函数功能：读卡操作,信息文件存储在应用程序当前目录下;
//参数：  1表示读基本信息，形成文字信息文件WZ.TXT、相片文件XP.WLT、ZP.BMP，如果有指纹信息形成指纹信息文件FP.DAT
//        2表示只读文字信息，形成文字信息文件WZ.TXT和相片文件XP.WLT
//        3读最新住址信息，形成最新住址文件NEWADD.TXT
//返回值：1	正确；0	读卡错误；2	没有最新住址信息；3	正确，并且有指纹信息；-1	相片解码错误
//	     -2	wlt文件后缀错误；-3	wlt文件打开错误；-4	wlt文件格式错误；-5	软件未授权；-11	无效参数
int  Read_Content(int Active);

//获取SAM ID
//参数：  SAMID数组长度需不小于40
//返回值：1表示成功，0表示失败
int  GetSAMID(char *SAMID);

//获取指定*.wlt对应的bmp文件，成功时BMP文件保存在当前运行目录下
//参数：需解码的wlt文件位置
//返回：1表示成功，0表示失败
int  GetBmpPhoto(const char* pszPath);

//复位SAM模块
//成功返回1；失败返回0
int  Reset_SAM();

//检测SAM_A状态
//返回值： 1表示SAM_A正常，0表示SAM_A状态异常
int  GetSAMStatus();

int  GetLastCardInfo(int index, char *value);

#ifdef __cplusplus
}
#endif

#endif
