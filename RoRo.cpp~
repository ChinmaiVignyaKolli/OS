#include<iostream>
using namespace std;
class Robin{
public:

int pid,at,bt,ct,tat,wt,wtime,finish;

void priort(int n,int tq);

};
Robin x[10];
Robin temp;
int main(){
int l;
Robin x;
int tq;
cout<<"Enter no of processes";
cin>>l;
cout<<"Enter time quantum";
cin>>tq;
x.priort(l,tq);

return 0;
}

void Robin::priort(int n,int tq){
float avgwt;

for(int i=0;i<n;i++){
cout<<"Enter"<<i<<"th pid"<<endl;
cin>>x[i].pid;
cout<<"Enter"<<i<<"th at"<<endl;
cin>>x[i].at;
cout<<"Enter"<<i<<"th bt"<<endl;
cin>>x[i].bt;

}



for(int i=0;i<n;i++){
 for(int j=0;j<n-i-1;j++){
	if(x[j].at>x[j+1].at){
	 
	temp=x[j];
	x[j]=x[j+1];
	x[j+1]=temp;
	}
    }
  }


int time_slice,complete=0,t=0,counter=0,Del=2199,I=0,flag[100],rt[100],idle=0,sum=0;

  for(int s=0;s<n;s++){
    flag[s]=0;
}
  for(int k=0;k<n;k++){
    rt[k]=x[k].bt;
 }
  int a[100];
  int front=0,rear=0;
  t=x[0].at;
  //cout<<"t:"<<t;

  while(complete<n)
  {
   sum=0;
   for(int i=0;i<n;i++)
   {
    if(x[i].at<=t && rt[i]>0 && flag[i]!=1) 
    {
      //cout<<"last process:"<<obj[6].AT<<"\n";
     I=i;
     a[rear]=i;
     flag[a[rear]]=1;
     rear=rear+1;
      //cout<<"front:"<<front<<"\n";
     if(front==0)
       I=0;
       //cout<<"I:"<<I<<"\n";
     
    }
  }
   //cout<<"front:"<<front<<"\n";
   // cout<<"I:"<<I<<"\n";
   
   if(I!=0) 
   if(rt[Del]!=0)
   {
     a[rear]=Del;
     rear=rear+1;
   }
   

   
   Del=a[front];
   //cout<<"Del:"<<Del<<"\n"; 
   if(rt[Del]<tq)
   {
    x[Del].ct=t+rt[Del];
    complete++;
    t=t+rt[Del];
    rt[Del]=0;
    flag[Del]=0;
     //cout<<"rem time:"<<rt[Del]<<"\n";
    //cout<<"t: inside"<<t<<"\n";
    front=front+1;
    continue;
   } 
   rt[Del]=rt[Del]-tq;
   //cout<<"rem time outside:"<<rt[Del]<<"\n";
   if(rt[Del]==0)
   {
    complete++;
    x[Del].ct=t+tq;
    flag[Del]=0;
    
   }

   
   front=front+1;
  
   for(int m=0;m<n;m++)
     sum=sum+flag[m];
   //cout<<"sum:"<<sum;
   if(sum==0)
   {
     //cout<<"Idle\n";
     t=x[Del].ct+1;
     //cout<<"t idle:"<<t<<"\n";
     front=0;
     rear=0;
   }
   
   
   else
  {
  t=t+tq ;
  //cout<<"t:"<<t<<"\n";
  //cout<<"\n"<<"\n";
  }
 }


for(int i=0;i<n;i++)
 {
  x[i].tat=x[i].ct-x[i].at;
 }



for(int i=0;i<n;i++)
 {
  x[i].wt=x[i].tat-x[i].bt;
 }






 float avg=0;
 cout<<"\nAverage wait time:";
 for(int i=0;i<n;i++)
 {
  avg=avg+x[i].wt;
 }
 cout<<avg/n<<"\n";

	for(int i=0;i<n;i++){
	cout<<x[i].at<<"	"<<x[i].bt<<"	"<<x[i].ct<<"	"<<x[i].tat<<"	"<<x[i].wt<<endl;
	}
   }



