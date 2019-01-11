#include<stdio.h>
#include<pthread.h>
int num=0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
void* work1(){
	int i=0;
	for(i=0;i<10;i++){
		//获取线程锁
		pthread_mutex_lock(&mutex);
		num++;
		sleep(2);
		printf("work1_num=%d\n",num);
		//解锁
		pthread_mutex_unlock(&mutex);
	}
}
void* work2(){
	int i=0;
	for(i=0;i<10;i++){
		//获取线程锁
		pthread_mutex_lock(&mutex);
		num++;
		sleep(1);
		printf("work2_num=%d\n",num);
		//解锁
		pthread_mutex_unlock(&mutex);
		//sleep(1);
	}
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
	//终止线程
	pthread_exit(NULL);
	pthread_mutex_destroy(&mutex);
	return 0;
}