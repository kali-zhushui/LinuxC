#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

int main(){
	int fd;
	creat("./test.txt",777);//创建公示栏
	fd=open("./test.txt",O_RDWR|O_APPEND);//打开公示栏
	write(fd,"math class",11);//向公示栏写 数学课
	sleep(8);//接电话
	write(fd,"cancel",10);//写取消
	close(fd);
}