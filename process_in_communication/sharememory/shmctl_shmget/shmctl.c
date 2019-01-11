#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdlib.h>
#include<string.h>
#define BUFFER_SIZE 100
int main(){
int key,shmid;
int pid;
char *p,buff[12];
key=ftok("/home",1);//创建键值
shmid=shmget(key,20,0666);//获取共享内存，返回值为共享内存段标识符
system("ipcs -m");//调用shell，查看共享内存状态
shmctl(shmid,IPC_RMID,buff);
//printf("\n input some string:\n");
//fgets(buff,BUFFER_SIZE,stdin);
return 0;
}