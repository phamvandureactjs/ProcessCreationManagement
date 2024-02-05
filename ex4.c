#include <stdio.h>
#include <pthread.h>
int cnt = 0;
pthread_mutex_t lock1;
pthread_mutex_t lock2;
pthread_t thread[2];
//pthread_t thread_2;
void* tryThis(void *arg){
//	pthread_mutex_lock(&lock1);
	unsigned long i = 0;
	cnt += 1;
	printf("Job %d has started\n", cnt);
	for(i = 0; i < 1000000; i++){
	}
	printf("Job %d has finished\n", cnt);
	return NULL;
//	pthread_mutex_unlock(&lock1);
}
void* handle_thread2(void *arg){
//	pthread_mutex_lock(&lock2);
	for(int i = 0; i < 1000000; i++){
		cnt++;
	}
//	pthread_mutex_unlock(&lock2);
}
int main(){
//	pthread_create(&thread_1, NULL, &handle_thread1, NULL);
//	pthread_create(&thread_2, NULL, &handle_thread1, NULL);
	int i = 0; 
	while(i < 2){
		pthread_create(&(thread[i]), NULL, &tryThis, NULL);
		i++;
	}
	pthread_join(thread[0], NULL);
	pthread_join(thread[1], NULL);
	return 0;
}
