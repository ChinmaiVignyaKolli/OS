#include<iostream>
using namespace std;
class Prio{
public:
float pid,at,bt,ct,tat,wt,wtime,p;
float rr;
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
float rr;
for(int i=0;i<n;i++){
cout<<"Enter"<<i<<"th pid"<<endl;
cin>>x[i].pid;
cout<<"Enter"<<i<<"th at"<<endl;
cin>>x[i].at;
cout<<"Enter"<<i<<"th bt"<<endl;
cin>>x[i].bt;

}
x[0].ct=x[0].at+x[0].bt;

for(int i=1;i<n;i++){

x[i].ct = x[i-1].ct + x[i].bt;

  if(x[i].at>x[i-1].ct){
	int j=i;
       while(j!=n){
	x[j].ct=x[j].ct+(x[i].at-x[i-1].ct);
        j++;
	}

  }
}

for(int i=0;i<n-1;i++){
for(int j=i+1;j<n;j++){
	if(x[j].at<=x[i].ct){
				
	rr=1+((x[i].ct-x[j].at)/x[j].bt)	;	          
          	
	x[j].rr=x[j].rr+rr;	
	}

}
}
	for(int i=0;i<n;i++){
	//cout<<x[i].at<<"  "<<x[i].bt<<"  "<<x[i].ct<<"  "<<x[i].tat<<" "<<x[i].wt<<endl;
        cout<<x[i].ct<<"  "<<x[i].rr<<endl;
       }

}

















































