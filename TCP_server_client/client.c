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
int main(int argc,char * argv[]){
struct sockaddr_in server_addr;
int sockfd;
char buf[SIZE];
int i=0;
char tt[]="exit\0";
char bu[4];
if(2!=argc){
printf("please input: ./client xxx.xxx.xxx.xxx\n");
exit(1);
}
//1.create socket:socket()
sockfd=socket(AF_INET,SOCK_STREAM,0);
//init
bzero(&server_addr,sizeof(struct sockaddr_in));
//1.set protocol
server_addr.sin_family=AF_INET;
//2.set port
server_addr.sin_port=htons(PORTNUM);
//3.set IPaddress
server_addr.sin_addr.s_addr=inet_addr(argv[1]);
while(1){
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	//connect() server
	connect(sockfd,(const struct sockaddr *)&server_addr,sizeof(struct sockaddr));
	//send()/ receive()
	printf("\nplease input data:\n");
	fgets(buf,SIZE,stdin);
	

		send(sockfd,buf,SIZE,0);
//close() connecion
close(sockfd);
}
}

