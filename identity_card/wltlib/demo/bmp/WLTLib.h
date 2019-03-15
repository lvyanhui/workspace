#ifndef CV_WLTLIB
#define CV_WLTLIB

#define CV_ERR_NONE              1
#define CV_ERR_LICENSE           2
#define CV_ERR_HDADER            3
#define CV_ERR_DATA              4
#define CV_ERR_UNINITIALIZED     5

#define CV_FORMAT_BMP            0
#define CV_FORMAT_RAW            1

#ifdef __cplusplus
extern "C" {
#endif
	//************************************
	// Method:    CV_Initialize
	// FullName:  CV_Initialize
	// Access:    public 
	// Returns:   int					��CV_ERR_XXX����
	// Parameter: const char * pLicense	��ȫģ����
	// Parameter: const int * pBaseData	С���任����
	// Desc:      ��ʼ������������ʱ����һ��
	//************************************
	int CV_Initialize(const char * pLicense, const int * pBaseData);

	//************************************
	// Method:    CV_Finalize
	// FullName:  CV_Finalize
	// Access:    public 
	// Returns:   int					��CV_ERR_XXX����
	// Desc:      ��ֹ�������˳�ʱ����һ��
	//************************************
	int CV_Finalize();

	//************************************
	// Method:    CV_Decode
	// FullName:  CV_Decode
	// Access:    public 
	// Returns:   int					��CV_ERR_XXX����
	// Parameter: unsigned char * pData ����������
	// Parameter: int length			���������ݳ���
	// Parameter: unsigned char * pOutBuffer	��������������������ⲿ��������㹻�ռ�
	// Parameter: int format			���������ʽ����CV_FORMAT_XXX����	
	// Parameter: int outLength			ʵ��������ݳ���
	// Desc:      ���뺯������֧�ֶ��̵߳���
	//************************************

	int CV_Decode(unsigned char *pData, 
		int length, 
		unsigned char * pOutBuffer, 
		int format, 
		int *outLength);

	//************************************
	// Method:    CV_ErrorInfo
	// FullName:  CV_ErrorInfo
	// Access:    public 
	// Returns:   void
	// Parameter: int errCode			������
	// Parameter: char * errMSg			����˵�����ڴ����ⲿ���䣬����128�ֽ�
	// Desc:      ��������ϸ��Ϣ˵��
	//************************************
	void CV_ErrorInfo(int errCode, char * errMSg);

	//************************************
	// Method:    CV_VersionInfo
	// FullName:  CV_VersionInfo
	// Access:    public 
	// Returns:   void
	// Parameter: char * version		�汾˵�����ڴ����ⲿ���䣬����128�ֽ�
	// Desc:      �汾��Ϣ
	//************************************
	void CV_VersionInfo(char * version);


#ifdef __cplusplus
}
#endif

#endif	// CV_WLTLIB
