#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#define N 6
#define haircut 0
#define wait 1
#define leave 2
sem_t mutex;
sem_t 
int state[N];
int customer[N]={0,1,2,3,4};

int main(){
pthread_t tid[N];
printf("Barber is sleeping");
for(i=0;i<N;i++){
pthread_create(&tid[i],NULL,runner,&customer[i]);
printf("customer %d entered",i+1);
}
}

void *runner(void * num){
while(1){
int *i = num;
waiting(*i);
left(*i);
}
}

void waiting(int c){
 sem_wait(&mutex);


 sem_post(&mutex);
 sem_wait(&S[c]);
}

void left(int c){
sem_wait(&mutex);


 sem_post(&mutex);
 sem_wait(&S[c]);

}


void haircut(i){
if(state[i]!= )



}


