#include<iostream>
using namespace std;
int a[10];
int n;
void * q2(void * arg)
{
if(n%2!=0){
cout<<"q2 ="<<a[(n-1)/2]<<endl;
}
else{
float m=(a[(n-1)/2]+a[(n+1)/2])/2.0;
cout<<"q2= "<<m<<endl;
}
}
void * min(void * arg){


cout<<"min ="<<a[0]<<endl;

}

void * max(void * arg){


cout<<"max ="<<a[n-1]<<endl;

}

void * q1(void * arg){


cout<<"q1 ="<<a[(n-1)/4]<<endl;

}

void * q3(void * arg){


cout<<"q3 ="<<a[(3*(n-1))/4]<<endl;

}


int main(){
int i,j;
cout<<"Enter the no of elements";
cin>>n;
cout<<"Enter the elements";
for(i=0;i<n;i++){
cin>>a[i];
}

for(i=0;i<n;i++){
	for(j=0;j<n-i-1;j++){
	int temp;
		if(a[j]>a[j+1]){
		temp=a[i];
		a[i]=a[j];
		a[j]=temp;
		}
	}
}
for(i=0;i<n;i++){
cout<<a[i];
}
pthread_t tid[5];
pthread_attr_t attr;
pthread_attr_init(&attr);
pthread_create(&tid[0],&attr,q1,NULL);
pthread_create(&tid[1],&attr,q2,NULL);
pthread_create(&tid[2],&attr,q3,NULL);
pthread_create(&tid[3],&attr,min,NULL);
pthread_create(&tid[4],&attr,max,NULL);
for(i=0;i<5;i++){
pthread_join(tid[i],NULL);
}
return 0;
}


















