#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/stat.h>
#include <sys/sem.h>
#include <stdlib.h>
int main(){
	int key;
	int semid;
	key=ftok("/home",1);
	struct sembuf sops;
	semid=semget(key,1,IPC_CREAT);
	sops.sem_num=0;
	sops.sem_op=-1;
	sops.sem_flg=SEM_UNDO;
	semop(semid,&sops,1);
	
	system("cp ./1.txt ../");
	return 0;
}