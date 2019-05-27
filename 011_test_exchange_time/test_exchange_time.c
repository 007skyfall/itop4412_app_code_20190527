/** 
* @file         test_uart_exchange_time.c 
* @brief        This is a test about time.
* @details  	This is a test about time.
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
#include <time.h>


#define errlog(errmsg) do{\
							perror(errmsg);\
							printf("%s -- %s -- %d\n", __FILE__, __func__, __LINE__);\
							exit(1);\
						 }while(0)


int main(int argc,const char *argv[])
{
	time_t timep;
	struct tm *tblock;
	
	time(&timep);
	printf("ctime/timep is: %s\n",ctime(&timep));
	
	printf("asctime is: %s\n",asctime(gmtime(&timep)));
	
	tblock = localtime(&timep);
	printf("localtime is: %s\n",asctime(tblock));
	printf("localtime is: %s\n",ctime(&timep));
	
return 0;
}