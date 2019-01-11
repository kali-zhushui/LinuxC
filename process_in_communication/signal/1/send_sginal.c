#include<unistd.h>
#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
int main(int argc,char *argv[]){
	int pid;
	pid=atoi(argv[1]);
	kill(pid,SIGQUIT);
	return 0;
}
