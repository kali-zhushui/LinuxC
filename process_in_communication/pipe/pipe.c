#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
int main()
{
char pipefd[2];
char  buff[6]="lsls";
char buf[6];
int pid;
pid=fork();
pipe(pipefd);
if(pid>0){
write(pipefd[1],buff,6);
printf("%s\n",pipefd[1]);
exit(0);
}
if(0==pid){
read(pipefd[0],buf,6);
printf("the number is%s\n",buff);
exit(0);
}
return 0;
}
