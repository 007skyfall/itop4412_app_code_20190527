/** 
* @file         test_open.c 
* @brief        This is a test how to use open API.
* @details  	This is a test how to use open API.
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
	int fd[3] = {0};
	char *leds = "./leds";
	char *test1 = "./test1";
	char *test2 = "./test2";

	#if 0
	if((fd[0] = open(leds,O_RDWR|O_NOCTTY|O_NDELAY)) < 0)
	{
		errlog("open leds");
	}
	else
	{
		printf("\n%s fd is %d\n",leds,fd[0]);

	}
	
	#endif

	#if 0

	if((fd[1] = open(test1,O_RDWR,0777)) < 0)
	{
		errlog("open test_01");
	}
	else
	{
		printf("%s fd is %d\n",test1,fd[1]);	
	}
	
	#endif

		
	if((fd[2] = open(test2,O_RDWR|O_CREAT,0777)) < 0)
	{
		errlog("open test_01");
	}
	else
	{
		printf("%s fd is %d\n",test1,fd[2]);	
	}

	for(int i = 0; i < 3; ++i)
	{
		close(fd[i]);
	}

return 0;
}