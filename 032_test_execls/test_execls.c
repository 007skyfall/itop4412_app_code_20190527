/** 
* @file         test_execls.c 
* @brief        This is a test execls.
* @details  	This is a test execls.
* @author       skyfall
* @date     	2019.05.28 
* @version  	v1.0.0
* @par Copyright (c):  
*       		none
* @par History:          
*   			none
**/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define errlog(errmsg) do{\
							perror(errmsg);\
							printf("%s -- %s -- %d\n", __FILE__, __func__, __LINE__);\
							exit(1);\
						 }while(0)


int main(int argc,const char *argv[])
{
	char *arg[] = {"ls","-a",NULL};
	
	if(fork() == 0)
	{
		//in child1
		printf("fork1 is OK;execl\n");
		
		if(execl("/bin/ls","ls","-a",NULL) == -1)
		{
			errlog("execl error");
		}
	}

	usleep(20000);
	if(fork() == 0)
	{
		//in child2
		printf("fork2 is OK;execv\n");
		
		if(execv("/bin/ls",arg) == -1)
		{
			perror("execv error");
			exit(1);
		}
	}
	
	usleep(20000);
	if(fork() == 0)
	{
		//in child3
		printf("fork3 is OK;execlp\n");
		
		if(execlp("ls","ls","-a",NULL) == -1)
		{
			errlog("execlp error");
		}
	}
	
	usleep(20000);
	if(fork() == 0)
	{
		//in child4
		printf("fork4 is OK;execvp\n");
		
		if(execvp("ls",arg) == -1)
		{
			errlog("execvp error");
		}
	}
	
	usleep(20000);
	if(fork() == 0)
	{
		//in child5
		printf("fork5 is OK;execle\n");
		
		if(execle("/bin/ls","ls","-a",NULL,NULL) == -1)
		{
			errlog("execle error");
		}
	}
	
	usleep(20000);
	if(fork() == 0)
	{
		//in child6
		printf("fork6 is OK;execve\n");
		
		if(execve("/bin/ls",arg,NULL) == -1)
		{
			errlog("execve error");
		}
	}

	usleep(20000);
	
return 0;
}