/** 
* @file         test_rmdir.c 
* @brief        This is a test rmdir API.
* @details  	This is a test rmdir API.
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
	if(argc < 2)
	{
		printf("Please input file path\n");
		return 1;
	}
//使用rmdir函数删除目录
	ret = rmdir(argv[1]);
	
	if(ret < 0)
	{
		printf("rmdir %s failed!\n",argv[1]);
		return 1;
	}
	printf("rmdir %s suceces！\n",argv[1]);
	
	return 0;
}