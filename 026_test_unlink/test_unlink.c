/** 
* @file         test_unlink.c 
* @brief        This is a test unlink API.
* @details  	This is a test unlink API.
* @author       skyfall
* @date     	2019.05.28 
* @version  	v1.0.0
* @par Copyright (c):  
*       		none
* @par History:          
*   			none
**/

#include <stdio.h>
//unlink函数头文件
#include <unistd.h>

int main(int argc,const char *argv[])
{
	int ret;
	
	if(argc < 2)
	{
		printf("usage %s unlink\n",argv[0]);
		return -1;
	}

//测试unlink函数
//unlink指向软链接，删除软链接；指向最后一个硬链接，相当于删除文件
	ret = unlink(argv[1]);
	if(ret)
	{
		printf("unlink is failed\n");
		return 1;
	}
	printf("unlink %s is success!\n",argv[1]);
	
	return 0;
}