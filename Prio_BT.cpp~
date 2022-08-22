#include<iostream>
using namespace std;
class sjf{
public:

int pid,at,bt,ct,tat,wt,wtime;

void priobt(int n);

};
sjf x[10];
sjf temp;
int main(){
int l;
sjf x;
cout<<"Enter no of processes";
cin>>l;
x.priobt(l);

return 0;
}

void sjf::priobt(int n){
float avgwt;
for(int i=0;i<n;i++){
cout<<"Enter"<<i<<"th pid"<<endl;
cin>>x[i].pid;
cout<<"Enter"<<i<<"th at"<<endl;
cin>>x[i].at;
cout<<"Enter"<<i<<"th bt"<<endl;
cin>>x[i].bt;

}
x[0].ct=x[0].at+x[0].bt;
//cout<<"ct[0] is"<<x[0].ct<<endl;
 


for(int i=1;i<n;i++){
 for(int j=1;j<n-i-1;j++){
	if(x[j].bt>x[j+1].bt){
	 
	temp=x[j];
	x[j]=x[j+1];
	x[j+1]=temp;
	}
    }
  }



sjf output[10];
int i,count[15]={0};
for(i=1;i<n;i++){

count[x[i].bt]++;
}
count[0]=0;
for(i=2;i<15;i++){
count[i]+=count[i-1];
}

for(i=n-1;i>0;i--)
{
output[count[x[i].bt]]=x[i];
count[x[i].bt]--;
}
for(i=1;i<n;i++){
x[i]=output[i];
}

for(int i=0;i<n;i++){
cout<<x[i].at<<"   "<<x[i].bt<<endl;
}





for(int i=1;i<n;i++){
x[i].ct=x[i-1].ct+x[i].bt;

}



for(int i=1;i<n;i++){
 x[i].wtime=0;
if(x[i].ct<x[i+1].at)
x[i].wtime=x[i].at-x[i-1].ct;
}

for(int i=1;i<n;i++){
 if(x[i].wtime!=0){
     int a=i;
	for(int y=a;y<n;y++){
	x[y].ct=x[y].ct+x[y].wtime;
	}
    }
}


for(int i=0;i<n;i++){
x[i].tat=x[i].ct-x[i].at;

}

float avg=0;
for(int i=0;i<n;i++){

x[i].wt=x[i].tat-x[i].bt;
avg=avg+x[i].wt;

}

avgwt=avg/n;
cout<<"Average wait time is "<<avgwt<<endl;




for(int i=0;i<n;i++){
cout<<x[i].at<<"   "<<x[i].bt<<"   "<<x[i].ct<<"   "<<x[i].tat<<"  "<<x[i].wt<<endl;
}



}
