#include<iostream>
using namespace std;
class srt{
public:

int pid,at,bt,ct,tat,wt,wtime,finish;

void priort(int n);

};
srt x[10];
srt temp;
int main(){
int l;
srt x;
cout<<"Enter no of processes";
cin>>l;
x.priort(l);

return 0;
}

void srt::priort(int n){
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



int count=0;
int b[10];
for(int i=0;i<n;i++){
b[i]=x[i].bt;
}

for(int i=0;i<n;i++){
cout<<b[i]<<endl;
}

int time;

x[9].bt=100;

		for(time=0;count!=n;time++){
			int smallest=9;

			for(int i=0;i<n;i++){
			 if(x[i].at<=time && x[i].bt<x[smallest].bt && x[i].bt>0){
                        // cout<<x[smallest].bt<<endl;
                        // cout<<i<<endl;
			   smallest=i;
			//cout<<i<<"   "<<smallest<<endl;
			 }
                          
                         
                     }
				

			x[smallest].bt--;

			 	if(x[smallest].bt==0){
			  	 count++;
			 	 x[smallest].finish=time+1;

			 	}
			 
			 

		}


	for(int i=0;i<n;i++){
        x[i].tat=x[i].finish-x[i].at;

	}

int avg=0;
for(int i=0;i<n;i++){
        x[i].wt=x[i].tat-b[i];
        avg=avg+x[i].wt;
	}
avgwt=avg/n;
cout<<"Average wait time : "<<avgwt<<endl;





	for(int i=0;i<n;i++){
	cout<<x[i].at<<"  "<<b[i]<<"  "<<x[i].finish<<"  "<<x[i].tat<<"  "<<x[i].wt<<endl;
	}
}




