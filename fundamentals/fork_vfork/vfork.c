#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
int main()
{
int result;
result=vfork();
if(result>0)
{
printf("parent\n");//fork子进程拥有独立的数据段堆栈，vfork子进程与父进程共享数据段，堆栈
//fork父子进程执行顺序不确定，而vfork是子进程先执行父进程后执行
exit(0);
}
else if(0==result)
{
printf("child\n");
exit(0);
}
return 0;
}
