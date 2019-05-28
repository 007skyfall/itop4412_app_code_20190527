/** 
* @file         test_pid.c 
* @brief        This is a test getpid.
* @details  	This is a test getpid.
* @author       skyfall
* @date     	2019.05.28 
* @version  	v1.0.0
* @par Copyright (c):  
*       		none
* @par History:          
*   			none
**/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc,const char *argv[])
{
	
	pid_t id_p,id;
	
	id_p = getppid();
	printf("ppid = %d\n",id_p);
	
	id = getpid();
	printf("pid = %d\n",id);
	
return 0;
}