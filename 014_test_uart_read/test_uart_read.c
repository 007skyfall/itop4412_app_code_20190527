/** 
* @file         test_uart_read.c 
* @brief        This is a test how to use uart read.
* @details  	This is a test how to use uart read.
* @author       skyfall
* @date     	2019.05.27 
* @version  	v1.0.0
* @par Copyright (c):  
*       		none
* @par History:          
*   			none
**/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>

int set_opt(int fd,int nSpeed, int nBits, char nEvent, int nStop);
/* "/dev/ttySAC3"是con2，靠近耳机接口的串口 */

int main(int argc,const char *argv[])
{
	int fd,nByte;
	char *uart3 = "/dev/ttySAC3";
	char buffer[512];
	char *uart_out = "please input\r\n";
	memset(buffer, 0, sizeof(buffer));
	if((fd = open(uart3, O_RDWR|O_NOCTTY))<0)
		printf("open %s is failed",uart3);
	else
	{
		set_opt(fd, 115200, 8, 'N', 1);
		write(fd,uart_out, strlen(uart_out));
		while(1)
		{
			while((nByte = read(fd, buffer, 512))>0)
			{
				buffer[nByte+1] = '\0';			
				write(fd,buffer,strlen(buffer));
				memset(buffer, 0, strlen(buffer));
				nByte = 0;
			}
		}
	}
	
return 0;

}

int set_opt(int fd,int nSpeed, int nBits, char nEvent, int nStop)
{
	struct termios newtio,oldtio;
	if  ( tcgetattr( fd,&oldtio)  !=  0) 
	{ 
		perror("SetupSerial 1");
		return -1;
	}
	bzero( &newtio, sizeof( newtio ) );
	newtio.c_cflag  |=  CLOCAL | CREAD;
	newtio.c_cflag &= ~CSIZE;

	switch( nBits )
	{
		case 7:
			newtio.c_cflag |= CS7;
			break;
		case 8:
			newtio.c_cflag |= CS8;
			break;
	}

	switch( nEvent )
	{
	case 'O':
		newtio.c_cflag |= PARENB;
		newtio.c_cflag |= PARODD;
		newtio.c_iflag |= (INPCK | ISTRIP);
		break;
	case 'E': 
		newtio.c_iflag |= (INPCK | ISTRIP);
		newtio.c_cflag |= PARENB;
		newtio.c_cflag &= ~PARODD;
		break;
	case 'N':  
		newtio.c_cflag &= ~PARENB;
		break;
	}

	switch( nSpeed )
	{
		case 2400:
			cfsetispeed(&newtio, B2400);
			cfsetospeed(&newtio, B2400);
			break;
		case 4800:
			cfsetispeed(&newtio, B4800);
			cfsetospeed(&newtio, B4800);
			break;
		case 9600:
			cfsetispeed(&newtio, B9600);
			cfsetospeed(&newtio, B9600);
			break;
		case 115200:
			cfsetispeed(&newtio, B115200);
			cfsetospeed(&newtio, B115200);
			break;
		case 460800:
			cfsetispeed(&newtio, B460800);
			cfsetospeed(&newtio, B460800);
			break;
		default:
			cfsetispeed(&newtio, B9600);
			cfsetospeed(&newtio, B9600);
			break;
	}
	if( nStop == 1 )
		newtio.c_cflag &=  ~CSTOPB;
	else if ( nStop == 2 )
	{
		newtio.c_cflag |=  CSTOPB;
	}
		newtio.c_cc[VTIME]  = 0;
		newtio.c_cc[VMIN] = 0;
		tcflush(fd,TCIFLUSH);
	if((tcsetattr(fd,TCSANOW,&newtio))!=0)
	{
		perror("com set error");
		return -1;
	}
	
	printf("set done!\n\r");
	return 0;
}


