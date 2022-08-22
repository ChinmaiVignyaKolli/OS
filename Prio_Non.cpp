#include<iostream>
using namespace std;
class Prio{
public:
int pid,at,bt,ct,tat,wt,wtime,p;

void prionon(int n);

};

Prio x[10];
Prio temp;
int main(){
int l;
Prio x;
cout<<"Enter no of processes";
cin>>l;
x.prionon(l);
return 0;
}

void Prio::prionon(int n){
float avgwt;
for(int i=0;i<n;i++){
cout<<"Enter"<<i<<"th pid"<<endl;
cin>>x[i].pid;
cout<<"Enter"<<i<<"th at"<<endl;
cin>>x[i].at;
cout<<"Enter"<<i<<"th bt"<<endl;
cin>>x[i].bt;
cout<<"Enter"<<i<<"th priority"<<endl;
cin>>x[i].p;
}
x[0].ct=x[0].at+x[0].bt;
float avg=0;
int time=x[0].ct;
for(int i=1;i<n;i++){
       int pos=i;
   for(int j=i+1;j<n;j++){
	if(x[j].p>x[pos].p && time>x[i].at){
		pos=j;

	}

   }
temp=x[i];
x[i]=x[pos];
x[pos]=temp;
x[i].ct=x[i-1].ct+x[i].bt;
	for(int l=1;l<n;l++){
		if(x[l].at>x[l-1].ct){
                    int diff=x[l].at-x[l-1].ct;
			int b=l;
                     while(b<n){
			x[b].ct=x[b].ct+diff;
			b++;
			}
		}

	}
x[i].tat=x[i].ct-x[i].at;
x[i].wt=x[i].tat-x[i].bt;
avg=avg+x[i].wt;
time=x[i].ct;
}
avgwt=avg/n;
cout<<avgwt<<endl;

	for(int i=0;i<n;i++){
	cout<<x[i].at<<"  "<<x[i].bt<<"  "<<x[i].ct<<"  "<<x[i].tat<<" "<<x[i].wt<<endl;
	}

}

















































