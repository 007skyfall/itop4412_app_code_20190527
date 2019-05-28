/** 
* @file         test_opendir.c 
* @brief        This is a test opendir API.
* @details  	This is a test opendir API.
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
#include <sys/types.h>
#include <dirent.h>

int main(int argc,const char *argv[])
{
	DIR *dir;
	
//检测参数	
	if(argc <2)
	{
		printf("usage %s open_dir\n",argv[0]);
		return -1;
	}
//使用opendir函数打开目录
	dir = opendir(argv[1]);
	if(dir==NULL)
	{
		printf("opendir %s is failed!\n",argv[1]);
		return -1;
	}
	printf("opendir %s is suceces！\n",argv[1]);
//使用closedir函数关闭目录
	closedir(dir);
	printf("closedir %s is suceces！\n",argv[1]);

	return 0;
}
