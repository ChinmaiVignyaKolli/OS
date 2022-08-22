#include<pthread.h>
#include<stdio.h>
int x;

void *runner(void *p){
int ul=atoi(p);
int i,j;
for(i=2;i<ul;i++){
	 x=0;
		for(j=2;j<=i/2;j++){
			if(i%j==0){
				x++;
				
			}

		}

		if(x==0){
		fprintf(stdout,"%d is prime\n",i);
	}
}


}

int main(int argc,char *argv[]){
pthread_t tid;
pthread_attr_t attr;
pthread_attr_init(&attr);
pthread_create(&tid,&attr,runner,argv[1]);

pthread_join(tid,NULL);
if(argc!=2){
fprintf(stderr,"Error");
return -1;
}

if(atoi(argv[1])<0){
fprintf(stderr,"Error wrong argument");
return -1;
}

return 0;
}


