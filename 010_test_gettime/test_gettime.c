/** 
* @file         test_gettime.c 
* @brief        This is a test about gettime.
* @details  	This is a test about gettime.
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
#include <time.h>

#define errlog(errmsg) do{\
							perror(errmsg);\
							printf("%s -- %s -- %d\n", __FILE__, __func__, __LINE__);\
							exit(1);\
						 }while(0)


int main(int argc,const char *argv[])
{
	time_t timep;
	
	time(&timep);
	printf("UTC time: %ld\n", timep);

	timep = time(NULL);
	printf("UTC time: %ld\n", timep);

	return 0;
}
