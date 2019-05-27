/** 
* @file         test_creat.c 
* @brief        This is a test how to use creat API.
* @details  	This is a test how to use creat API.
* @author       skyfall
* @date     	2019.05.27 
* @version  	v1.0.0
* @par Copyright (c):  
*       		none
* @par History:          
*   			none
**/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>


#define errlog(errmsg) do{\
							perror(errmsg);\
							printf("%s -- %s -- %d\n", __FILE__, __func__, __LINE__);\
							exit(1);\
						 }while(0)

int main(int argc,const char * argv[])
{
	int fd[4] = {0};
	char *leds = "./leds";
	char *test1 = "./test1";
	char *test2 = "./test2";

	//需要新建的文件test3
	char *test3 = "./test3";

	# if 0
	//使用open函数打开文件
	if((fd[0] = open(leds, O_RDWR|O_NOCTTY|O_NDELAY))<0)
	{
		errlog("open leds");
	}
	else
	{
		printf("%s fd is %d\n",leds,fd[0]);
	
	}
	
	//使用open函数打开不存在的文件，不添加O_CREAT标识符，会报错
	if((fd[1] = open(test1, O_RDWR))<0)
	{
		errlog("open test1");
	}
	else
	{
		printf("%s fd is %d\n",test1,fd[1]);
	
	}

	#endif
	
	//打开文件创建文件，添加标志位O_CREAT表示不存在这个文件则创建文件
	if((fd[2] = open(test2, O_RDWR|O_CREAT,0664))<0)
	{
		errlog("open test2");
	}
	else
	{
		printf("%s fd is %d\n",test2,fd[2]);
	
	}

	if((fd[3] = creat(test3,0777))<0)
	{
		errlog("open test3");
	}
	else
	{
		printf("%s fd is %d\n",test3,fd[3]);
	
	}

	for(int i = 0; i < 4; ++i)
	{
		close(fd[i]);
	}

return 0;
}
