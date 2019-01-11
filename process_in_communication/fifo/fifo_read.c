#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>
int main(){
int fd;
int buff,i=10;
fd=open("./fifo",O_RDONLY);
for(i=0;i<10;i++){
	read(fd,&buff,12);
	printf("%d\n",buff*3);
	}
close(fd);
unlink("./fifo");
return 0;
}
