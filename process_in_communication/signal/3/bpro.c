#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/stat.h>
#include <sys/sem.h>
int main(){
	int fd;
	int key;
	int semid;
	key=ftok("/home",6);
	struct sembuf sops;
	semid=semget(key,1,IPC_CREAT);
	sops.sem_num=0;
	sops.sem_op=-1;
	sops.sem_flg=SEM_UNDO;
	semop(semid,&sops,1);
	
	fd=open("./test.txt",O_RDWR|O_APPEND);//打开公示栏
	write(fd,"English exam\0",12);//向公示栏写 英语课考试
	sops.sem_num=0;
	sops.sem_op=1;
	sops.sem_flg=SEM_UNDO;
	semop(semid,&sops,1);
	close(fd);
}