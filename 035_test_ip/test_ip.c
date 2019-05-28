/** 
* @file         test_ip.c 
* @brief        This is a test ip.
* @details  	This is a test ip.
* @author       skyfall
* @date     	2019.05.28 
* @version  	v1.0.0
* @par Copyright (c):  
*       		none
* @par History:          
*   			none
**/
#include <stdio.h>

int main(int argc,const char *argv[])
{

    char a[] = "192.168.1.199";
    unsigned int ip = 0;
    unsigned char *p = (unsigned char *)&ip;
    int a1, a2, a3, a4;
    sscanf(a, "%d.%d.%d.%d", &a1, &a2, &a3, &a4);
    printf("a4 = %u\n", a4);
    printf("a3 = %u\n", a3);
    printf("a2 = %u\n", a2);
    printf("a1 = %u\n", a1);
   
    *p = a4;
    printf("a4 = %u\n", a4);
    p++;
    *p = a3;
    printf("a3 = %u\n", a3);
    p++;
    *p = a2;
    printf("a2 = %u\n", a2);
    p++;
    *p = a1;
    printf("a1 = %u\n", a1);
    puts("****************************************************");
    printf("%u\n", ip);

    return 0;
}



