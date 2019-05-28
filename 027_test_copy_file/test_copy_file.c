/** 
* @file         test_copy_file.c 
* @brief        This is a test copy_file.
* @details  	This is a test copy_file.
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
#define LENTH 1024

int main(int argc,const char *argv[])
{
	int fd_src,fd_dst;
	char buffer[LENTH];
	const char *old_file,*new_file;
	int read_len;
	
	old_file = argv[1];
	new_file = argv[2];
	
	if(argc < 3)
	{
		printf("usage %s src_file dst_file\n",argv[0]);
		return -1;
	}

	
	fd_src = open(old_file,O_RDONLY);
	if(fd_src < 0)
	{
		printf("Please make sure file path\n");
		return -1;
	}
	
	
	fd_dst = open(new_file,O_RDWR|O_CREAT|O_TRUNC,0664);
	if(fd_dst < 0)
	{
		printf("Please make sure file path\n");
		return -1;
	}

	
	while((read_len = read(fd_src,buffer,LENTH))> 0)
	{
		printf("read_len = %d\n",read_len);
		write(fd_dst,buffer,read_len);
	}
	
	
	close(fd_src);
	close(fd_dst);
	
	printf("cp to is finished!\n");
	printf("cp %s to %s is success!\n",old_file,new_file);
	
	return 0;
}
