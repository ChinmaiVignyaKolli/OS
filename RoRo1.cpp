#include<iostream>
using namespace std;

class RR
{
 
int pid,AT,BT,CT,TAT,WT;
 public:
 void create();
 void sort_algo();
 void print();
 void algo();
 void output();
};

RR obj[100];
int n;
int l=0;

void RR::create()
{
 cout<<"Enter pid,AT,BT of process "<<l<<"\n";
 cin>>pid;
 cin>>AT;
 cin>>BT;
 TAT=CT=WT=0;
 l++;
}
 

void RR::print()
{
 cout<<"\n"<<"Sorted\n";
 for(int i=0;i<n;i++)
 {
  cout<<obj[i].pid<<"\t"<<obj[i].AT<<"\t"<<obj[i].BT<<"\n";
 
 }
}

void RR::sort_algo()
{
 RR temp;
 for(int i=0;i<n;i++)
 for(int j=0;j<n-i-1;j++)
 {
  if(obj[j].AT>obj[j+1].AT)
  {
   temp=obj[j];
   obj[j]=obj[j+1];
   obj[j+1]=temp;
  }
 }
}

void RR::algo()
{
  int time_slice,complete=0,t=0,counter=0,Del=2199,I=0,flag[100],rt[100],idle=0,sum=0;

  for(int s=0;s<n;s++)
    flag[s]=0;

  cout<<"Enter time slice\n";
  cin>>time_slice;

  for(int k=0;k<n;k++)
    rt[k]=obj[k].BT;
 
  int a[100];
  int front=0,rear=0;
  t=obj[0].AT;
  //cout<<"t:"<<t;

  while(complete<n)
  {
   sum=0;
   for(int i=0;i<n;i++)
   {
    if(obj[i].AT<=t && rt[i]>0 && flag[i]!=1) 
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
   if(rt[Del]<time_slice)
   {
    obj[Del].CT=t+rt[Del];
    complete++;
    t=t+rt[Del];
    rt[Del]=0;
    flag[Del]=0;
     //cout<<"rem time:"<<rt[Del]<<"\n";
    //cout<<"t: inside"<<t<<"\n";
    front=front+1;
    continue;
   } 
   rt[Del]=rt[Del]-time_slice;
   //cout<<"rem time outside:"<<rt[Del]<<"\n";
   if(rt[Del]==0)
   {
    complete++;
    obj[Del].CT=t+time_slice;
    flag[Del]=0;
    
   }

   
   front=front+1;
  
   for(int m=0;m<n;m++)
     sum=sum+flag[m];
   //cout<<"sum:"<<sum;
   if(sum==0)
   {
     //cout<<"Idle\n";
     t=obj[Del].CT+1;
     //cout<<"t idle:"<<t<<"\n";
     front=0;
     rear=0;
   }
   
   
   else
  {
  t=t+time_slice ;
  //cout<<"t:"<<t<<"\n";
  //cout<<"\n"<<"\n";
  }
  }


}

void RR::output()
{
 cout<<"pid"<<"\t"<<"AT\t"<<"BT\t"<<"CT\t"<<"TAT\t"<<"WT\t"<<"\n";
 for(int i=0;i<n;i++)
 {
  cout<<obj[i].pid<<"\t"<<obj[i].AT<<"\t"<<obj[i].BT<<"\t"<<obj[i].CT<<"\t"<<obj[i].TAT<<"\t"<<obj[i].WT<<"\n";
 
 }
  float avg=0;
 cout<<"\nAverage wait time:";
 for(int i=0;i<n;i++)
 {
  avg=avg+obj[i].WT;
 }
 cout<<avg/n<<"\n";

}


int main()
{
 
 RR O;
 cout<<"Enter no of processes\n";
 cin>>n;

 for(int i=0;i<n;i++)
  obj[i].create();
 O.sort_algo();
 O.print();
 O.algo();
 O.output();
 return(0);
 }
 
