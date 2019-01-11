#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<unistd.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define PORTNUM 4321
#define SIZE 128
int main(int argc,char* argv[]){
	
	struct sockaddr_in server_addr;
	int sockfd,new_fd,nsize,size_addr;
	if(2!=argc){
		printf("please in put ./client addr");
		exit(1);
	}
	char buf[SIZE];
	//1,create socket
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	// init addr 
		bzero(&server_addr,sizeof(struct sockaddr_in));
		// (1)set protocol family
		server_addr.sin_family=AF_INET;
		// 2)set port
		server_addr.sin_port=htons(PORTNUM);//htons host to net short
		// 3)set ip
		server_addr.sin_addr.s_addr=inet_addr(argv[1]);

	size_addr=sizeof(struct sockaddr);
	while(1){
		connect(sockfd,(const struct sockaddr *)&server_addr,size_addr);
		// send/reci' data
		printf("please input data:\n");
		fgets(buf,SIZE,stdin);
		if(strcmp(buf,"exit")==0){
		exit(0);
		}
		send(sockfd,buf,SIZE,0);
		printf("what sent is %s\n",buf);
	}
		close(sockfd);
		exit(0);
}
