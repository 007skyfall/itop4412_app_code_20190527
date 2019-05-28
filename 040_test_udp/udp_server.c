/** 
* @file         udp_server.c 
* @brief        This is a test about udp.
* @details  	This is a test about udp.
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

int main(int argc, const char *argv[])
{
	char recvline[1024] = {0};

	int sockfd;
	struct sockaddr_in servaddr;

	/* 创建一个UDP连接的socket */
	sockfd = socket(PF_INET, SOCK_DGRAM, 0);

	/* 变量servaddr清零 */
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);	
	servaddr.sin_port = htons(50001);

	/* 绑定servaddr到创建的socket上 */
	bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

	/* 接收客户端发送的数据 */
	recvfrom(sockfd, recvline, 1024, 0, NULL, NULL);

	printf("%s\n", recvline);

	/* 关闭socket连接 */
	close(sockfd);
}