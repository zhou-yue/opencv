#include <iconv.h>  
#include <stdlib.h>  
#include <stdio.h>  
#include <unistd.h>  
#include <fcntl.h>  
#include <string.h>  
#include <sys/stat.h> 

#define N 128

/*
* iconv_open	iconv_t iconv_open(const char *tocode, const char *fromcode);
*		返回一个转换句柄,供以下两个函数使用
* icovt_t	size_t iconv(iconv_t cd,char **inbuf,size_t *inbytesleft,char **outbuf,size_t *outbytesleft);
*		从inbuf中读取字符,转换后输出到outbuf中
*		inbytesleft用以记录还未转换的字符数,outbytesleft用以记录输出缓冲的剩余空间
* icovt_close	int iconv_close(iconv_t cd);
*		关闭转换句柄,释放资源
*/

/* 
* pint为输入的字符串，pout为得到的字符串
* from_charset为原码制
* to_charset为目标码制
*/

int transcod(char *pint,char *pout) 
{
	iconv_t cd;  
	char *from_charset = "gb2312";	//原码制
	char *to_charset = "utf-8";		//目标码制

	cd = iconv_open(to_charset, from_charset);

	size_t lenpint = strlen(pint);
	size_t lenpout = sizeof(pout);

	if (iconv(cd, &pint, &lenpint, &pout, &lenpout) == -1)  
		return -1; 

	iconv_close(cd); 
	*(pout + 1) = '\0';	//结束符

	return 0;
