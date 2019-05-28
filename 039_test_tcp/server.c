/** 
* @file         server.c 
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
	int sfp, nfp, num = 0;
	struct sockaddr_in s_add,c_add;
	socklen_t sin_size;
	unsigned short portnum = 8888;

	char buffer[100] = {0};

	printf("Hello,welcome to my server !\r\n");

	sfp = socket(AF_INET, SOCK_STREAM, 0);
	if(-1 == sfp)
	{
			errlog("socket fail! \r\n");
	}

	printf("socket ok !\r\n");

	bzero(&s_add,sizeof(struct sockaddr_in));
	s_add.sin_family=AF_INET;
	s_add.sin_addr.s_addr=htonl(INADDR_ANY);
	s_add.sin_port=htons(portnum);

	if(-1 == bind(sfp,(struct sockaddr *)(&s_add), sizeof(struct sockaddr)))
	{
			errlog("bind fail !\r\n");
	}

	printf("bind ok !\r\n");

	if(-1 == listen(sfp,128))
	{
			errlog("listen fail !\r\n");
	}

	printf("listen ok!\r\n");



	sin_size = sizeof(struct sockaddr_in);

	nfp = accept(sfp, (struct sockaddr*)(&c_add), &sin_size);
	if(-1 == nfp)
	{
			errlog("accept fail !\r\n");
	}

	printf("accept ok!\r\nServer start get connect from %d : %d\r\n", 
							ntohl(c_add.sin_addr.s_addr), ntohs(c_add.sin_port));
	while(1)
	{
			memset(buffer, 0, 100);
			sprintf(buffer, "hello,welcome to my server(%d) \r\n", num++);
			send(nfp, buffer, strlen(buffer), 0);
			usleep(500000);
	}

	close(nfp);
	close(sfp);

return 0;
}
