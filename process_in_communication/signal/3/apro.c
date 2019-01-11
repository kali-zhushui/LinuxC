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
	semctl(semid,0,SETVAL,1);
	
	creat("./test.txt",777);//创建公示栏
	sops.sem_num=0;
	sops.sem_op=-1;			//获取信号量
	sops.sem_flg=SEM_UNDO;
	semop(semid,&sops,1);
	
	fd=open("./test.txt",O_RDWR|O_APPEND);//打开公示栏
	write(fd,"math class\0",10);//向公示栏写 数学课
	sleep(8);//接电话
	write(fd,"cancel\0",6);//写取消
	//write(fd,"cancel",7);
	sops.sem_num=0;		
	sops.sem_op=+1;		//释放信号量
	sops.sem_flg=SEM_UNDO;
	semop(semid,&sops,1);
	close(fd);
}