#include<pthread.h>
#include<stdio.h>

int b[100]={0};
int n;
int a[10]={0};
int i;
void *runner_mean(void *x){
float sum=0;
for(i=0;i<n;i++){
sum+=a[i];
}
float mean=sum/n;
fprintf(stdout,"%f is mean\n",mean);

}

void *runner_median(void *x){
int i,j,temp;
for(i=0;i<n;i++){
	for(j=0;j<n-i-1;j++){
		if(a[j]>a[j+1]){
		temp = a[j];
		a[j]=a[j+1];
		a[j+1]=temp;
		}	
	}

}
	if(n%2!=0){
	fprintf(stdout,"%d is median\n",a[n/2]);
	}
	else{
	fprintf(stdout,"%d %d are medians\n",a[n/2],a[(n/2)-1]);
	}
}
void *runner_mode(void *x){
int max=a[0];
for(i=0;i<n;i++){
	b[a[i]]++;
	if(a[i]>max){
	max=a[i];

}

}
int l=0,Bmax=0,lmax=0;
for(l=0;l<max;l++){	
		if(b[l]>Bmax){
		Bmax=b[l];
		lmax=l;
	}
}
fprintf(stdout,"%d is mode\n",lmax);
}
int main(){
int i;

printf("Enter size of array");
scanf("%d",&n);
printf("Enter array");
for(i=0;i<n;i++){
scanf("%d",&a[i]);
}

pthread_t tid[4];
pthread_attr_t attr;
pthread_attr_init(&attr);
pthread_create(&tid[0],&attr,runner_mean,NULL);
pthread_create(&tid[1],&attr,runner_median,NULL);
pthread_create(&tid[2],&attr,runner_mode,NULL);

for(i=0;i<3;i++){
pthread_join(tid[i],NULL);
}

return 0;
}
