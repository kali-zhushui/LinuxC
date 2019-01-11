#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
int main(){
		int pid;
		int i;
		int fd;
		int flag=1;
		pid=fork();
		if(pid>0)exit(0);
	else if(0==pid){
		setsid();
		chdir("/");
		umask(0);
		for(i=0;i<65535;i++)
			close(i);
		while(1){
		if(1==flag)
		fd=open("./xzq.txt",O_RDWR|O_CREAT|O_APPEND);
		write(fd,"项志强",7);
		close(fd);
		flag=0;
		}
	}	
return 0;
}
//1、创建子进程
//2、脱离父进程
//3、改变工作目录
//4、清除掩码
//5、关闭打开的文件
//6、完成守护进程的工作
