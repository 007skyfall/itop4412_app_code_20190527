/** 
* @file         test_fork.c 
* @brief        This is a test fork.
* @details  	This is a test fork.
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
#include <sys/types.h>
       
int main(int argc,const char *argv[])
{
	pid_t pid;
	int i = 3;
	
	pid = fork();
	if(pid == -1)
	{
		printf("fork is failed\n");
		return 1;
	}

	else if(pid > 0)
	{

		while(--i)
		{
		printf("The father i = %d\n",i);
		printf("The father return value is %d\n",pid);
		printf("The father pid is %d\n",getpid());
		printf("The father ppid is %d\n",getppid());
		sleep(1);
		
		}

	}
	else
	{
		while(--i)
		{
		printf("The child i = %d\n",i);
		printf("The child return value is %d\n",pid);
		printf("The child pid is %d\n",getpid());
		printf("The child ppid is %d\n",getppid());
		sleep(1);
		}
	}
	
return 0;
}