/** 
* @file         test_link.c 
* @brief        This is a test link API.
* @details  	This is a test link API.
* @author       skyfall
* @date     	2019.05.28 
* @version  	v1.0.0
* @par Copyright (c):  
*       		none
* @par History:          
*   			none
**/
#include <stdio.h>
//link函数头文件
#include <unistd.h>

int main(int argc,const char *argv[])
{
	int ret;
	
	if(argc < 3)
	{
		printf("usage %s src dst_link\n",argv[0]);
		return -1;
	}

//测试link函数
	ret = link(argv[1],argv[2]);
	if(ret)
	{
		printf("link is failed\n");
		return -1;
	}
	printf("link old_file:%s to new_file %s is success!\n",argv[1],argv[2]);
	
	return 0;
}