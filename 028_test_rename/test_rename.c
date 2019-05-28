/** 
* @file         test_rename.c 
* @brief        This is a test rename.
* @details  	This is a test rename.
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
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

//argv[1] is oldpath ; argv[2] is newpath
int main(int argc,const char *argv[])
{
	int ret;
	if(argc < 3)
	{
		printf("usage %s src_file dst_file\n",argv[0]);
		return -1;
	}
	
	if((ret = rename(argv[1],argv[2])) < 0)
	{
		printf("rename is error!\n");
	}
		
	printf("rename old_file: %s to new_file: %s success!\n",argv[1],argv[2]);
	
	return 0;
}
