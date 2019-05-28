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
    char a[2][5] = {{4,3,6,2,9}, {56,32,8,1,99}};
    char *p =(char *)a;
    
    int i, j;
    for(i = 0; i < 10; i++)
    {
        for(j = 1; j < 10 - i; j++)
        {
            if (p[j] < p[j - 1])
            {
                char tmp = p[j];
                p[j] = p[j - 1];
                p[j - 1] = tmp;
            }
        }
    }
    
    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 5; j++)
        {
            printf("%d\n", a[i][j]);
        }
    }
    return 0;
}



