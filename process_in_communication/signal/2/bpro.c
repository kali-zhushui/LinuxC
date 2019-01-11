#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
int main(){
	int fd;
	fd=open("./test.txt",O_RDWR|O_APPEND);//打开公示栏
	write(fd,"English exam",13);//向公示栏写 英语课考试
	close(fd);
}