//创建共享内存、映射共享内存、添加数据到共享内存、分离共享内存
//打开共享内存、映射共享内存、读取共享内存的数据、分离共享内存、删除共享内存
#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 2048
typedef struct shemem{
	int shm_flg;//用来判断是否为空
	char buf[SIZE];
}shm;

int main()
{
	int key,shmid;
	int flag;
	shm *shmp;
	int pid;
	char buffer[SIZE];

	key=ftok("/home",1);//创建键值

	
	shmid=shmget(key,sizeof(shm),IPC_CREAT);//获取共享内存，返回值为共享内存段标识符
	if(-1==shmid){
		printf("shmget is error\n");
		exit(1);
	}
	shmp=shmat(shmid,NULL,0);//将共享内存映射到指定地址
//printf("\n input some string:\n");
//fgets(buff,BUFFER_SIZE,stdin);
//添加数据到共享内存
			while(flag){
				if(1==flg){
					sleep(1);
					printf("what wrote is\n",buffer);
				}
				fgets(buffer,SIZE,stdin);//
				strncpy(shmp->buf,buffer,SIZE);
				if(strcmp(buffer,"end",3)==0)
					flag=0;
			}
			//分离共享内存
			
return 0;
}