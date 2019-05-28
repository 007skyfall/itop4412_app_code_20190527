/** 
* @file         test_read.c 
* @brief        This is a test how to use read API.
* @details  	This is a test how to use read API.
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
#include <string.h>

#define errlog(errmsg) do{\
							perror(errmsg);\
							printf("%s -- %s -- %d\n", __FILE__, __func__, __LINE__);\
							exit(1);\
						 }while(0)



#define MAX_SIZE 1024

int main(int argc,const char *argv[])
{
	int fd;
	ssize_t length_w;
	ssize_t ret;
	char *testwrite = "./testwrite";
	char buffer_write[] = "Hello Write Function!";
	char buffer_read[MAX_SIZE];
	
	if((fd = open(testwrite,O_RDWR|O_CREAT,0664)) < 0)
	{
		errlog("open");
	}
	
	length_w = write(fd,buffer_write,strlen(buffer_write));
	if(length_w == -1)
	{
		errlog("write");
	}
	else
	{
		printf("Write Function OK!\n");
	}
	close(fd);
	
	if((fd = open(testwrite,O_RDWR|O_CREAT,0664))<0)
	{
		errlog("open");
	}
	
	if((ret = read(fd,buffer_read,length_w)) < 0)
	{
		errlog("read");  
	}
	printf("Files Content is %s \n",buffer_read);

	close(fd);
	
return 0;
}
