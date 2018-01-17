#include <iostream>
#include <opencv2/opencv.hpp>
#include "CvxText.h" 
#include <time.h>
 
#define N 128
using namespace cv; 

int main(int argc, char *argv[])  
{  
	clock_t start,finish;
	double time = 0;

	start = clock();
	wchar_t intbuf[N] = L"你好world";	//宽字节字符，因为要显示汉字
	
	/*
	* 如果你的代码的编码格式本身就是GBK，可省略文字转码过程
	* 如果最后部分汉字能显示，部分不能显示，有可能是编码问题，需要执行以下代码，并修改makefile调用相关函数
	* 
	* wchar_t outbuf[N] = L"";
	* utf82gbk((char *)outbuf, (char *)intbuf, sizeof(outbuf)); 
	*/ 

	IplImage *image = cvLoadImage(argv[1]); 

	CvxText text("simhei.ttf"); 		//"zenhei.ttf"为黑体常规  
	float p = 0.5;  			//修改透明度
	text.setFont(NULL, NULL, NULL, &p);
	text.putText(image, intbuf, cvPoint(500, 400), CV_RGB(0, 0, 0));

	cv::Mat newimg = cv::cvarrToMat(image);	//转为Mat型
	cv::imwrite("new.jpg",newimg);		//保存生成的图片到./new.jpg
	finish = clock();
	time = (double)(finish - start)/CLOCKS_PER_SEC;
	printf("time = %lf\n",time);		//计算程序执行时间

	namedWindow("效果图",0);
	cv::imshow("效果图",newimg);		//显示效果图
	cv::waitKey(-1);			  //按任意键关闭图片
	cv::destroyWindow("效果图");
	cvReleaseImage(&image);			  //销毁窗口，释放对象

	return 0;  
} 
