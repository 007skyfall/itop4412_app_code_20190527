/** 
* @file         test_readdir.c 
* @brief        This is a test readdir API.
* @details  	This is a test readdir API.
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
	struct dirent *catlog;
//检测参数	
	if(argc <2)
	{
		printf("usage %s read_dir\n",argv[0]);
		return -1;
	}
//使用opendir函数打开目录
	dir = opendir(argv[1]);
	if(dir==NULL)
	{
		printf("usage %s open_dir\n",argv[0]);
		return -1;
	}
	printf("opendir %s is suceces！\n",argv[1]);
	
//使用readdir读取目录argv[1]
	catlog = readdir(dir);
	if(catlog == NULL)
	{
		printf("readdir %s is failed!\n",argv[1]);
		return -1;
	}
	printf("%s d_ino is %ld\n ",argv[1],catlog->d_ino);
		
//使用closedir函数关闭目录
	closedir(dir);
	
	return 0;
}