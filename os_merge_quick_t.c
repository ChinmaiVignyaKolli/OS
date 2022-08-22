#include<pthread.h>
#include<stdio.h>
int n;
int a[10];
int p,q;

void *runner_merge(void *x){

MergeSort(p,q);
}

void MergeSort( int p,int q)
{
	int mid=(p+q)/2;
	
	if(p<q)
	{
			MergeSort(p,mid);
			MergeSort(mid+1,q);
			Merge(p,q);	
	}
				
}


void Merge( int beg , int end)
{
	int mid=(beg+end)/2;
	int i=beg,j=mid +1,k=0;
	int b[100];
	
	while((i<=mid )&& (j<=end))
	{
			if(a[i]<a[j])
				{
				 	b[k]=a[i];
				 	i++;
				}
			else
				{
					b[k]=a[j];
					j++;
				}
		k++;
	}
	
	while(i<=mid)
	{
		b[k]=a[i];
		k++;
		i++;
	}
	while(j<=end)
	{
		b[k]=a[j];
		k++;
		j++;
	}
	
	for(i=beg;i<=end;i++)
		a[i]=b[i-beg];
}

int main(){
pthread_t tid;
pthread_attr_t attr;
pthread_attr_init(&attr);
int i;
printf("\n Enter the size of the array");
scanf("%d",&n);
printf("\n Enter the array");
for(i=0;i<n;i++){
scanf("%d",&a[i]);
}
printf("\n Enter first and last index");
scanf("%d %d",&p,&q);
pthread_create(&tid[0],&attr,runner_merge,NULL);
pthread_create(&tid[1],&attr,runner_quick,NULL);

for(i=0;i<2;i++){
pthread_join(tid[i],NULL);
}
return 0;
}
