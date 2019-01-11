#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main()
{
int pid;
pid=vfork();
if(pid>0){
  wait(NULL);//挂起调用他的函数，直到其子进程执行完

	printf("this is a parent access!\n");
	exit(0);
}
else if(0==pid){
	printf("this is a child access\n");
	execl("/bin/ps","ps","aux",NULL);//很有可能会在执行后退出进程
	printf("this is a parent access!\n");
	exit(0);
}
return 0;
}
