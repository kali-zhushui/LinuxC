#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
void main()
{
int pid,i,j;
int num=0;
pid=vfork();
if(pid>0)
{
for(i=0;i<15;i++){
num++;
printf("parent access number is %d\n",num);}
}
else if(0==pid)
{
for(j=16;j<30;j++){
  num++;
  printf("child num=%d\n",num);
  }
}
exit(0);
}
