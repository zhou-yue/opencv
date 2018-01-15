#include <iconv.h>  
#include <stdlib.h>  
#include <stdio.h>  
#include <unistd.h>  
#include <fcntl.h>  
#include <string.h>  
#include <sys/stat.h> 
#include <locale.h>  
#define N 128

int utf82gbk(char *gbkStr, const char *srcStr, int maxGbkStrlen) {  
	if (NULL == srcStr) {  
		printf("Bad Parameter：srcStr\n");  
		return -1;  
	} 

	if (NULL == setlocale(LC_ALL, "zh_CN.utf8")) //设置转换为unicode前的码,当前为utf8编码  
	{  
		printf("Bad Parameter：zh_CN.utf8\n");  
		return -1;  
	}  

	int unicodeLen = mbstowcs(NULL, srcStr, 0);

	if (unicodeLen <= 0) {  
		printf("Can not Transfer!!!\n");  
		return -1;  
	}  
	wchar_t *unicodeStr = (wchar_t *) calloc(sizeof(wchar_t), unicodeLen + 1);  
	mbstowcs(unicodeStr, srcStr, strlen(srcStr)); //将utf8转换为unicode

	if (NULL == setlocale(LC_ALL, "zh_CN.gbk")) //设置unicode转换后的码,当前为gbk  
	{  
		printf("Bad Parameter：zh_CN.gbk\n");  
		return -1;  
	}  
	int gbkLen = wcstombs(NULL, unicodeStr, 0);

	if (gbkLen <= 0) {  
		printf("Can not Transfer!!!\n");  
		return -1;  
	} 
	else if (gbkLen >= maxGbkStrlen) //判断空间是否足够
	{  
		printf("Dst Str memory not enough\n");  
		return -1;  
	}  
	wcstombs(gbkStr, unicodeStr, gbkLen);  
	gbkStr[gbkLen] = 0; //添加结束符

	free(unicodeStr);  
	return gbkLen;  
} 