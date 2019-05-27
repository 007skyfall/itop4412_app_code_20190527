/** 
* @file         test_uart_open.c 
* @brief        This is a test about open uart.
* @details  	This is a test about open uart.
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


int main( int argc,const char *argv[] )
{
	int fd;
	
	char *uart3 = "/dev/ttySAC3";
	
	if((fd = open(uart3,O_RDWR|O_CREAT,0777)) < 0)
	{
		errlog("open uart3");
	}
	else
	{
		printf("open %s is success!\n",uart3);
	}
	
	close(fd);
	
return 0;
}
