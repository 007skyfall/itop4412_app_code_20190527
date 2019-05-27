/** 
* @file         test_buzzer.c 
* @brief        This is a test about buzzer.
* @details  	This is a test about buzzer.
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
#include <sys/ioctl.h>

#define errlog(errmsg) do{\
							perror(errmsg);\
							printf("%s -- %s -- %d\n", __FILE__, __func__, __LINE__);\
							exit(1);\
						 }while(0)

#define BUZZER_C 2

int main(int argc,const char *argv[])
{
	char *buzzer_ctl = "/dev/buzzer_ctl";
	int fd,buzzer_c;
	int num = 10;
	int i = atoi(argv[1]);
	int j = atoi(argv[2]);
	
	buzzer_c = BUZZER_C;
	
	if(atoi(argv[1]) >= buzzer_c )
	{
		printf("argv[1] is 0 or 1\n");
		exit(1);
	}
	
	if((fd = open(buzzer_ctl,O_RDONLY|O_NOCTTY|O_NDELAY)) < 0)
	{
		errlog("openbuzzer_ctl");
		exit(1);
	}
	
	while(--num)
	{
		ioctl(fd,!i,!j);
		sleep(3);
	}
	
	close(fd);
	
	return 0;
}
