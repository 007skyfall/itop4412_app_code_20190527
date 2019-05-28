/** 
* @file         udp_client.c 
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
	int sockfd;
	struct sockaddr_in servaddr;

	if(argc != 2)
	{
			printf("usgae: ./client [ip]\n");

			return -1;
	}

	/* 创建一个UDP的socket连接 */
	sockfd = socket(PF_INET, SOCK_DGRAM, 0);

	/* 变量servaddr清零 */
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(50001);
	servaddr.sin_addr.s_addr = inet_addr(argv[1]);

	char sendline[100];
	sprintf(sendline, "Hello, world!");

	/*  发送数据 */
	sendto(sockfd, sendline, strlen(sendline), 0, (struct sockaddr *)&servaddr, sizeof(servaddr));

	/* 关闭socket连接 */
	close(sockfd);

	