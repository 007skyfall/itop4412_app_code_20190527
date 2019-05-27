/** 
* @file         test_precisiontime.c 
* @brief        This is a test how to use time.
* @details  	This is a test how to use time.
* @author       skyfall
* @date     	2019.05.27 
* @version  	v1.0.0
* @par Copyright (c):  
*       		none
* @par History:          
*   			none
**/

/*函数time头文件*/
#include<time.h>
/*函数gettimeofday和settimeofday的头文件*/
#include<sys/time.h>
#include<stdio.h>

int function() 
{ 
	 unsigned int i,j; 
	 double y; 
	 for(i=0;i<1000;i++)
	 {
		 for(j=0;j<1000;j++) 
		 y=i/(j+1); //耗时操作
	 } 
	 
	 return y;
} 

int main(int argc,const char *argv[]) 
{ 
	struct timeval tpstart,tpend; 
	float timeuse; 

	gettimeofday(&tpstart,NULL); //记录开始时间
	function();
	
	gettimeofday(&tpend,NULL); //记录结束时间
	
	timeuse = 1000000*(tpend.tv_sec-tpstart.tv_sec)+ 
	tpend.tv_usec-tpstart.tv_usec; //计算差值
	timeuse /= 1000000; 
	
	printf("Used Time:%fs!\n",timeuse); 

	return 0;
}
