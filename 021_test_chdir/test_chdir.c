/** 
* @file         test_chdir.c 
* @brief        This is a test chdir API.
* @details  	This is a test chdir API.
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

#define LENTH 255

#define errlog(errmsg) do{\
							perror(errmsg);\
							printf("%s -- %s -- %d\n", __FILE__, __func__, __LINE__);\
							exit(1);\
						 }while(0)

int main(int argc,const char *argv[])
{
	int ret;
	char pwd[LENTH];

//检测参数	
	if(argc < 3)
	{
		printf("usage %s src_dir rmdir_dir\n",argv[0]);
		return -1;
	}
	
//getcwd函数获取当前目录		
	if(!getcwd(pwd,LENTH))
	{
		errlog("getcwd");
		return -1;
	}
	printf("getcwd pwd is %s\n",pwd);
	
//使用chdir函数转入其他目录
	ret = chdir(argv[1]);
	if(ret)
	{
		printf("Please make sure file path\n");
		return -1;
	}
	printf("chdir %s is success！\n",argv[1]);
	
//转入其他目录，完成操作
//使用rmdir函数删除目录
	ret = rmdir(argv[2]);
	if(ret < 0)
	{
		printf("rmdir %s failed!\n",argv[2]);
		return -1;
	}
	printf("rmdir %s is success！\n",argv[2]);
	
//再次使用chdir回到pwd保存的目录
	ret = chdir(pwd);
	if(ret)
	{
		printf("Please make sure file path\n");
		return -1;
	}
	printf("chdir %s is success！\n",pwd);

	return 0;
}