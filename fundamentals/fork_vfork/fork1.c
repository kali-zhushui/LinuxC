#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
void main()
{
int i,j,num=0;
int result;
   result= fork();
	if(result>0){
		for(i=0;i<15;i++)
		{
		num++;
		printf("the parent value is %d\n",num);
		}
		exit(0);
	}
	if(0==result)
	{
	    num=15;
   		for(i=1;i<16;i++)
   		{
  		 num++;
		 printf("the child value is %d\n",num);
 	     }
		exit(0);
	}
}
