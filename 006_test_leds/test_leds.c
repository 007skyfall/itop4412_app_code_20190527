/** 
* @file         test_leds.c 
* @brief        This is a test about led.
* @details  	This is a test about led.
* @author       skyfall
* @date     	2019.05.27 
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
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include <sys/ioctl.h>

#define errlog(errmsg) do{\
							perror(errmsg);\
							printf("%s -- %s -- %d\n", __FILE__, __func__, __LINE__);\
							exit(1);\
						 }while(0)

#define LED_NUM 2
#define LED_C 2
//cmd为0，则灭，为1，则亮；
//io为0则是靠近蜂鸣器的小灯，为1则是靠近独立按键的小灯

int main(int argc,const char *argv[])
{
	int fd,led_num,led_c;
	char *leds = "/dev/leds";

	led_num = LED_NUM;
	led_c = LED_C;
	
	printf("argv[1] is cmd!argv[2] is io !\n"); 

	//对传入的参数进行判断，超出范围直接退出
	if (atoi(argv[1]) >= led_c)
	{
		printf("argv[1] is 0 or 1!\n");
		exit(1);
	}
	if (atoi(argv[2]) >= led_num) 
	{
		printf("argv[2] is 0 or 1!\n");
		exit(1);
	}
	//使用ioctl函数将参数传入内核
	if((fd = open(leds, O_RDONLY|O_NOCTTY|O_NDELAY)) < 0)
	{
		errlog("leds open");   
	}
		
	else
	{
		ioctl(fd,atoi(argv[1]),atoi(argv[2]));
		printf("ioctl %s success!\n",leds);
	}
	
	close(fd);
	
	return 0;
}
