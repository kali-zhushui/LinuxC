#include<stdio.h>
#include<unistd.h>
#include<stdio.h>
#include<signal.h>

void func(int a){
	printf("i get %d\n",SIGQUIT-1);
}
int main(){
	signal(SIGQUIT,func);
	pause();
	return 0;
}
