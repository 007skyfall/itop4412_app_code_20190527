/** 
* @file         test_chmod.c 
* @brief        This is a test chmod API.
* @details  	This is a test chmod API.
* @author       skyfall
* @date     	2019.05.27 
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


#define errlog(errmsg) do{\
							perror(errmsg);\
							printf("%s -- %s -- %d\n", __FILE__, __func__, __LINE__);\
							exit(1);\
						 }while(0)

int main(int argc,const char *argv[])
{
	int fd[2] = {0};
	int ret = 0;
	char *test01  = "test01";
	char test02[] = "test02";

//chmod函数测试	
	fd[0] = open(test01,O_RDWR|O_CREAT|O_TRUNC,0001);

	ret = chmod(test01,0777);
	if(ret < 0)
	{
		printf("Please make sure file path\n");
		return 1;
	}
	printf("chmod %s 0777 is success!\n",test01);

//fchmod函数测试		
	fd[1] = open(test02,O_RDWR|O_CREAT|O_TRUNC,0001);
	if(fd[1] < 0)
	{
		printf("Please make sure file path\n");
		return 1;
	}
	ret = fchmod(fd[1],0555);
	if(ret < 0)
	{
		printf("Please make sure file path\n");
		return 1;
	}
	printf("fchmod %s 0555 is success!\n",test02);

	close(fd[0]);
	close(fd[1]);

	return 0;
}
