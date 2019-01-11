#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/stat.h>
#include <sys/sem.h>
#include <stdlib.h>
int main(){
	int fd;
	int semid;
	struct sembuf sops;
	int key=ftok("/home",1);
	semid = semget(key,1,IPC_CREAT);
	semctl(semid,0,SETVAL,0);
	fd=open("./1.txt",O_CREAT|O_APPEND|O_RDWR);
	write(fd,"hello world",11);
	sleep(10);
	write(fd,"dame!",5);
	sops.sem_num=0;
	sops.sem_op=+1;
	sops.sem_flg=SEM_UNDO;
	semop(semid,&sops,1);
	close(fd);
	return 0;
}