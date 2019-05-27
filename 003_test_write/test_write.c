/** 
* @file         test_write.c 
* @brief        This is a test how to use write API.
* @details  	This is a test how to use write API.
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
#include <string.h>


#define errlog(errmsg) do{\
							perror(errmsg);\
							printf("%s -- %s -- %d\n", __FILE__, __func__, __LINE__);\
							exit(1);\
						 }while(0)

int main(int argc,const char *argv[])
{
	int fd;
	char *testwrite = "./testwrite";
	ssize_t length_w;
	char buffer_write[] = "Hello Write Function!";

	printf("sizeof(buffer_write) = %ld\n",sizeof(buffer_write));
	printf("strlen(buffer_write) = %ld\n",strlen(buffer_write));


	if((fd = open(testwrite, O_RDWR|O_CREAT,0664))<0)
	{
		errlog("open is failed\n"); 
	}

	length_w = write(fd,buffer_write,strlen(buffer_write) + 1);
	if(length_w == -1)
	{
		errlog("write");
	}
	else
	{
		printf("Write Function OK!\n");
	}
	printf("buffer_write = %s\n",buffer_write);

	close(fd);
	
return 0;
}
