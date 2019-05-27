/** 
* @file         test_argc.c 
* @brief        This is a test how to use argc.
* @details  	This is a test how to use argc.
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


//argument count变元计数
//argument value变元值
int main(int argc,const char *argv[])
{


	printf("The Program name is %s\n",argv[0]);
	
	printf("The command line has %d arguments!\n",argc-1);

	if(argc < 2)
	{
		errlog("argc");
	}
	
	if(!strcmp(argv[1],"aa"))
	{
		puts("argv[1] is valid!");
	}
	else if(!strcmp(argv[2],"bb"))
	{
		puts("argv[2] is valid!");
	}
	else 
	{
		puts("argc is great than 3");
	}
		
	return 0;
}
