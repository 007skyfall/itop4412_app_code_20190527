/** 
* @file         test_mkdir.c 
* @brief        This is a test mkdir API.
* @details  	This is a test mkdir API.
* @author       skyfall
* @date     	2019.05.28 
* @version  	v1.0.0
* @par Copyright (c):  
*       		none
* @par History:          
*   			none
**/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>
#include <stdlib.h>


int main(int argc,const char *argv[])
{
	int ret;
		
//检测参数	
	if(argc <2)
	{
		printf("Please input file path\n");
		return -1;
	}
//使用mkdir函数新建目录
	ret = mkdir(argv[1],0777);
	if(ret < 0)
	{
		printf("mkdir %s failed!\n",argv[1]);
		return 1;
	}
	printf("mkdir %s suceces！\n",argv[1]);
	
	return 0;
}