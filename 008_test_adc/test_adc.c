/** 
* @file         test_adc.c 
* @brief        This is a test about adc.
* @details  	This is a test about adc.
* @author       skyfall
* @date     	2019.05.27 
* @version  	v1.0.0
* @par Copyright (c):  
*       		none
* @par History:          
*   			none
**/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdint.h>
#include <termios.h>
#include <sys/ioctl.h>

#define errlog(errmsg) do{\
							perror(errmsg);\
							printf("%s -- %s -- %d\n", __FILE__, __func__, __LINE__);\
							exit(1);\
						 }while(0)

int main(int argc,const char *argv[])
{
	int fd;
	char *adc = "/dev/adc";
	char buffer[512];
	int len=0, r=0;
	
	memset(buffer,0,sizeof(buffer));
	printf("adc is ready!\n");
	
	if((fd = open(adc, O_RDONLY|O_NOCTTY|O_NDELAY)) < 0)
	{
		errlog("open adc");
	}

	else
	{
		printf("open adc success!\n");
		
		len=read(fd,buffer,10);	
		
		if(len == 0)
			printf("return null\n");
		else
		{
			r = atoi(buffer);
			r = (int)(r*10000/4095);	//Datas  transition to Res
			printf("res value is %d\n",r);
		}			
	}
	
	close(fd);

return 0;

}
















