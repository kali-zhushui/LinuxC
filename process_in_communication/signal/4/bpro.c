#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/stat.h>
#include <sys/sem.h>
int main(){
	int key;
	int semid;
	key=ftok("/home",6);
	struct sembuf sops;
	semid=semget(key,1,IPC_CREAT);
	sops.sem_num=0;
	sops.sem_op=-1;
	sops.sem_flg=SEM_UNDO;
	semop(semid,&sops,1);
	
	printf("hello world\n");
	sops.sem_num=0;
	sops.sem_op=1;
	sops.sem_flg=SEM_UNDO;
	semop(semid,&sops,1);
}