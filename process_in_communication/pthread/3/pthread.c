#include<stdio.h>
#include<pthread.h>
int num=0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_ready= PTHREAD_COND_INITIALIZER;

void* work1(){
	int i=0;
	for(i=0;i<5;i++){
		//获取线程锁
		pthread_mutex_lock(&mutex);
		num++;
		printf("work1_num=%d\n",num);
		//解锁
		pthread_mutex_unlock(&mutex);
		sleep(2);
	}
	//终止线程
		if(num>=5){
			printf("work1 is finished\n");
		pthread_cond_signal(&cond_ready);
		}
		pthread_exit(NULL);
}
void* work2(){
	pthread_mutex_lock(&mutex);
	if(num<5)
	{
	pthread_cond_wait(&cond_ready,&mutex);
	}
		num=10;		
		printf("work2 is finished num=%d\n",num);
		pthread_mutex_unlock(&mutex);
			sleep(1);
		//终止线程
		pthread_exit(NULL);
}

int main(){
	
	//初始化线程锁
	pthread_mutex_init(&mutex,NULL);	
	pthread_t pthreadid[2];
	
	//删除线程锁
	
	//创建two线程s
	pthread_create(&pthreadid[0],NULL,work1,NULL);
	pthread_create(&pthreadid[1],NULL,work2,NULL);
	//等待线程结束
	 pthread_join(pthreadid[0],NULL);
	 pthread_join(pthreadid[1],NULL);
	pthread_mutex_destroy(&mutex);
	return 0;
}