#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
int fd,i=10;
int ss=4;
mkfifo("./fifo",666);
fd=open("./fifo",O_WRONLY);
for(i=0;i<10;i++){
	ss++;
	write(fd,&ss,4);
	printf("what sent is %d",ss);
	sleep(1);
	}
}
