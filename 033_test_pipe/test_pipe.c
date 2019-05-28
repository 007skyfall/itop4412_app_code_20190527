/** 
* @file         test_pipe.c 
* @brief        This is a test pipe.
* @details  	This is a test pipe.
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
#include <sys/types.h>

#define errlog(errmsg) do{\
							perror(errmsg);\
							printf("%s -- %s -- %d\n", __FILE__, __func__, __LINE__);\
							exit(1);\
						 }while(0)


//进程读函数
void read_data(int *);
//进程写函数 
void write_data(int *);


int main(int argc,const char *argv[])
{
	int pipes[2],rc;
	pid_t pid;
		
	rc = pipe(pipes);	//创建管道                 
	if(rc == -1)
	{
		errlog("pipes");
	}
		
	pid = fork();	//创建进程 

	switch(pid)
	{
		case -1:
			errlog("fork");
		case 0:
			read_data(pipes);	//相同的pipes,子进程
			break;
		default:
			write_data(pipes);	//相同的pipes,父进程
			break;
	}	
	
return 0;
}

//进程读函数
void read_data(int pipes[])
{
	int c,rc;
	
	//由于此函数只负责读，因此将写描述关闭(资源宝贵)
	close(pipes[1]);
	
	//阻塞，等待从管道读取数据
	//int 转为 unsiged char 输出到终端
	while( (rc = read(pipes[0],&c,1)) > 0 )
	{  		
		putchar(c);       		                       
	}
	close(pipes[0]);
	exit(0);
}

//进程写函数
void write_data(int pipes[])
{
	int c,rc;

	//关闭读描述字
	close(pipes[0]);                          

	while( (c=getchar()) > 0 )
	{
		rc = write( pipes[1], &c, 1);	//写入管道
		if( rc == -1 )
		{
			perror("Parent: write");
			close(pipes[1]);
			exit(1);
		}
	}

	close( pipes[1] );
	exit(0);
}
