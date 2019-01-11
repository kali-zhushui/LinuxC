#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>
#define SIZE 1024
typedef struct msgbuf{
	long mtype;
	char mdata[SIZE];
}msg;

int main()
{
	int msgid;
	int key,type,pid;
	int i;
	msg msgp;
	key=ftok("/home",8);
	char buffer[SIZE];
	//创建消息队列
	msgid = msgget(key,IPC_CREAT);
	//向消息队列写入消息
	printf("send type is 88 then exit\n");
	while(1)
	{
		printf("please input type : ");
		scanf("%d",&type);
		msgp.mtype=type;
		printf("\n");
		if(type==88)break;
		printf("Please input data\n");
		scanf("%s",buffer);
		strncpy(msgp.mdata,buffer,SIZE);
		printf("msg.mdata data = %s\n",msgp.mdata);
		msgsnd(msgid,&msgp,sizeof(msgp),0);
	}
	//删除消息队列
	msgctl(msgid,IPC_RMID,NULL);
	return 0;
}