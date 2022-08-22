#include<iostream>
using namespace std;
#include<stdlib.h>
#define MAX 10

int part=0;
int arr[10];
int n;
void merge(int l,int m,int r){
int i,j,k;
int nl = m-l+1;
int nr = r-m;
int L[nl],R[nr];

for(i=0;i<nl;i++){
 L[i]=arr[l+i];
}

for(j=0;j<nr;j++){
 R[i]= arr[m+j+1];
}

i=0;j=0;k=l;

while(i<nl && j<nr){

	if(L[i]<=R[j]){
	arr[k]=L[i];
	i++;
	}
	else{
	arr[k]=R[j];
	j++;
	}

    k++;
}

if(i<nl)
{
	arr[k]=L[i];
	i++;
	k++;
}
if(j<nr)
{
	arr[k]=R[j];
	j++;
	k++;
}

}



void mergesort(int l,int r)
{
	if(l<r)
	{
		int mi=(l+r)/2;
		mergesort(l,mi);
		mergesort(mi+1,r);
		merge(l,mi,r);
	}

}





void *merge_sort(void* arg){
int x=n;
int thread_part=part++;

int low=thread_part * ( x/ 4);
int high=(thread_part+1) *(x/ 4)-1;

int mid = (low+high)/2;
if(low < high)
  {
	mergesort(low,mid);
	mergesort(mid+1,high);
	merge(low,mid,high);
  }
}



int main(){

cout<<" Enter no of values ";
cin>>n;
cout<<"Enter values for array";
for(int i=0;i<n;i++){
cin>>arr[i];
}


pthread_t p[4];
pthread_attr_t attr;
pthread_attr_init(&attr);

for(int i=0;i<4;i++){
pthread_create(&p[i],&attr,merge_sort,NULL);
}
for(int i=0;i<4;i++){
pthread_join(p[i],NULL);
}

merge(0,(n/2 -1)/2 ,n/2 -1);
merge(n/2,((3*n)/2 - 1)/2,n-1);
merge(0,(n-1)/2,n -1);

cout<<"After sort";
for(int i=0;i<n;i++){
cout<<arr[i]<<endl;
}
return 0;
}



