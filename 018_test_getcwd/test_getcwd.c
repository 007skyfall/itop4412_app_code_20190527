/** 
* @file         test_getcwd.c 
* @brief        This is a test getcwd API.
* @details  	This is a test getcwd API.
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

#define __USE_GNU
#define _GNU_SOURCE


#define errlog(errmsg) do{\
							perror(errmsg);\
							printf("%s -- %s -- %d\n", __FILE__, __func__, __LINE__);\
							exit(1);\
						 }while(0)

#define LENTH 255

int main(int argc,const char *argv[])
{
	char pwd[LENTH];
	char *wd = NULL;
	char *current_dir = NULL;
			
	if(!getcwd(pwd,LENTH))
	{
		errlog("getcwd");
	}
	printf("getcwd pwd is %s\n",pwd);
	

	wd = getwd(pwd);

	if(!wd)
	{
		errlog("getcwd");
	}
	printf("getwd pwd is %s\n",wd);
	
	current_dir = (char*)malloc(sizeof(char) * LENTH);
	if(NULL ==current_dir)
	{
		errlog("get_current_dir_name");
	}
	
	//current_dir = get_current_dir_name();
	puts("aaaaa");
	puts(current_dir);
	printf("get_current pwd is %s\n",current_dir);
	puts("abbb");
	if(NULL != current_dir)
	{
		free(current_dir);
		current_dir = NULL;
	}
	
	return 0;
}
