#include<iostream>
using namespace std;
class Prio{
public:
int pid,at,bt,ct,tat,wt,wtime,p,finish;

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
int b[10];

for(int i=0;i<n;i++){
//cout<<"Enter"<<i<<"th pid"<<endl;
//cin>>x[i].pid;
cout<<"Enter"<<i<<"th at"<<endl;
cin>>x[i].at;
cout<<"Enter"<<i<<"th bt"<<endl;
cin>>x[i].bt;
cout<<"Enter"<<i<<"th priority"<<endl;
cin>>x[i].p;
}

for(int i=0;i<n;i++){
b[i]=x[i].bt;

}



float avg=0;

int count=0;
int time;

x[9].p=0;

		for(time=0;count!=n;time++){
			int large=9;

			for(int i=0;i<n;i++){
			 if(x[i].at<=time && x[i].p > x[large].p && x[i].bt>0){
                        // cout<<x[smallest].bt<<endl;
                        // cout<<i<<endl;
			   large=i;
			//cout<<i<<"   "<<smallest<<endl;
			 }
                          
                         
                     }
				

			x[large].bt--;

			 	if(x[large].bt==0){
			  	 count++;
			 	 x[large].finish=time+1;

			 	}
			 
			 

		}

for(int i=0;i<n;i++){
        x[i].tat=x[i].finish-x[i].at;

	}

//int avg=0;
for(int i=0;i<n;i++){
        x[i].wt=x[i].tat-b[i];
        avg=avg+x[i].wt;
	}
avgwt=avg/n;
cout<<"Average wait time is "<<avgwt<<endl;


	for(int i=0;i<n;i++){
        cout<<endl;
	cout<<x[i].at<<"  "<<b[i]<<"  "<<x[i].finish<<"  "<<x[i].tat<<" "<<x[i].wt<<endl;
        
	}

}

















































