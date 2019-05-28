/** 
* @file         client.c 
* @brief        This is a test about tcp.
* @details  	This is a test about tcp.
* @author       skyfall
* @date     	2019.05.27 
* @version  	v1.0.0
* @par Copyright (c):  
*       		none
* @par History:          
*   			none
**/

#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

#define errlog(errmsg) do{\
							perror(errmsg);\
							printf("%s -- %s -- %d\n", __FILE__, __func__, __LINE__);\
							exit(1);\
						 }while(0)




int main(int argc,const char *argv[])
{
	int cfd;
	int recbyte;
	char buffer[1024] = {0};

	struct sockaddr_in s_add;
	unsigned short portnum = 8888;

	printf("Hello,welcome to client!\r\n");

	if(argc != 2)
	{
			printf("usage: echo ip\n");
			return -1;
	}

	cfd = socket(AF_INET, SOCK_STREAM, 0);
	if(-1 == cfd)
	{
			errlog("socket fail ! \r\n");
	}

	printf("socket ok !\r\n");

	bzero(&s_add,sizeof(struct sockaddr_in));
	s_add.sin_family=AF_INET;
	s_add.sin_addr.s_addr= inet_addr(argv[1]);
	s_add.sin_port=htons(portnum);
	printf("s_addr = %d ,port : %d\r\n",s_add.sin_addr.s_addr,s_add.sin_port);

	if(-1 == connect(cfd,(struct sockaddr *)(&s_add), sizeof(struct sockaddr)))
	{
			errlog("connect fail !\r\n");
	}

	printf("connect ok !\r\n");

	while(1)
	{
			if(-1 == (recbyte = read(cfd, buffer, 1024)))
			{
					errlog("read data fail !\r\n");
			}

			printf("read ok\r\nREC:\r\n");
			buffer[recbyte]='\0';
			printf("%s\r\n",buffer);
	}

	close(cfd);

	return 0;

}
