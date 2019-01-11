#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<unistd.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#define PORTNUM 4321
#define SIZE 128
int main(){
	struct sockaddr_in server_addr;
	struct sockaddr_in client_addr;
	int sockfd,new_fd,nsize,size_addr,pid;
	char buf[SIZE],buff[]="exit",bu[4];
	int i=0;
	//1,create socket
	sockfd=socket(AF_INET,SOCK_STREAM,0);//*
	// init addr 
	bzero(&server_addr,sizeof(struct sockaddr_in));
	// (1)set protocol family
	server_addr.sin_family=AF_INET;
	// 2)set port
	server_addr.sin_port=htons(PORTNUM);//htons host to net short
	// 3)set ip
	server_addr.sin_addr.s_addr=htonl(INADDR_ANY);
	//2,bind()
    bind(sockfd,(const struct sockaddr *)&server_addr,sizeof(struct sockaddr_in));
	//3,listener the port()
    listen(sockfd,16);
	//4,wait for conection 
	
	//5,send/reci' data
	if(pid==vfork()==0){
		while(1){
			size_addr=sizeof(struct sockaddr);
			new_fd=accept(sockfd,(struct sockaddr *)&client_addr,&size_addr);
			printf("client %s connection is successfull\n",inet_ntoa(client_addr.sin_addr));//整型 ip 转字符型
				nsize=recv(new_fd,buf,SIZE,0);
				buf[nsize]='\0';
				for(i=0;i<4;i++)
				{
				printf("%c",buf[i]);
				bu[i]=buf[i];
				}	
				if(strcmp(bu,"exit")==0)
				{
					exit(0);
				}
			printf("what recv'ed is %s\n",buf);
			}
	}
	
	 close(sockfd);
	 exit(0);
    // send(sockfd, const void *buf, size_t len,0);
	//6,terminate the conection
}
