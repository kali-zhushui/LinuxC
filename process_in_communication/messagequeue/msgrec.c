#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<unistd.h>
#include<string.h>
#define SIZE 1024
typedef struct msgbuf{
	long mtype;
	char mdata[SIZE];
}msg;
int msgid;
void work(){
	msg msgp;
	printf("11111111111111\n");
	while(1){
		msgrcv(msgid,&msgp,sizeof(msg),0,0);
		printf("type is %d\n",(int)msgp.mtype);
		if(msgp.mtype<100&&msgp.mtype>0){
			
			if(msgp.mtype==88)break;
			printf("type is %d\n",(int)msgp.mtype);
			printf("data is %s \n",msgp.mdata);
		}
	}
}
int main(){
	int key,msgid,i=0;
	
	int pid;
	char buffer[SIZE];
	key=ftok("/home",8);
	//dakai消息队列
	msgid = msgget(key,IPC_CREAT);
	for(i=0;i<3;i++)
	{
		pid=fork();
		if(0==pid){
			work();
		}
	}
	return 0;
}