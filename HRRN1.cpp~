#include<iostream>

using namespace std;

const int n=4;

class process
{
	unsigned int pid, at, bt, rbt, ct, tat, wt;
	
	public:
		
		void sort(process x[], int k);
		void init(process x[]);
		void disp(process x[]);
		void hrrn_npe(process x[]);		
		
};
void process::init(process x[])
{
	for(int i=0; i<n; i++)
	{	cout<<"Enter pid ";
		cin>>x[i].pid;
		cout<<"Enter at ";
		cin>>x[i].at;
		cout<<"Enter bt ";
		cin>>x[i].bt;
		x[i].ct=x[i].tat=x[i].wt=1000;
		x[i].rbt=x[i].bt;
	}
	cout<<"Display after init():\n";
	disp(x);
}
void process::disp(process x[])
{
	cout<<"PID\tAT\tBT\tCT\tTAT\tWT\tRBT\n";
	for(int i=0; i<n; i++)
		cout<<x[i].pid<<"\t"<<x[i].at<<"\t"<<x[i].bt<<"\t"<<x[i].ct<<"\t"<<x[i].tat<<"\t"<<x[i].wt<<"\t"<<x[i].rbt<<endl;
}
void process::sort(process x[], int k)
{
	if (k==1)
	for(int i=0; i<n; i++)//sorts according to AT
	{
		for(int j=0; j<n-i-1; j++)
			if(x[j].at>x[j+1].at)
			{
				process temp=x[j];
				x[j]=x[j+1];
				x[j+1]=temp;
			}
	}
	
	else if(k==2)
	for(int i=0; i<n; i++)//sorts according to CT
	{
		for(int j=0; j<n-i-1; j++)
			if(x[j].ct>x[j+1].ct)
			{
				process temp=x[j];
				x[j]=x[j+1];
				x[j+1]=temp;
			}
	}
	
}
unsigned int sys_clk=0;
void process::hrrn_npe(process x[])
{
	sys_clk=0;
	sort(x, 1);
	//x[0].disp(x);
	sys_clk=x[0].at;
	for(int i=0; i<=n; i++)//runs once for each process
	{
		cout<<"Running process loop\n";
		int max_rat=0;
		int ind=-1;
		int j=0;
		
		for(j=0; j<n; j++)//find the process with the highest RR
		{
			if((x[j].rbt>0)&&(x[j].at<=sys_clk))
			{
				cout<<"found valid process:\n";
				if((1+(sys_clk-x[j].at)/(float)x[j].bt)>max_rat)
				{
					max_rat=1+(sys_clk-x[j].at)/(float)x[j].bt;
					ind=j;
				}
			}
		}
		if(ind==-1)
		{
			for(int k=0; k<n; k++)
			{
				if(x[k].rbt>0)
				{
					sys_clk=x[k].at;
					break;
				}
			}
		}
		else
		{
			cout<<"HRR pro at "<<ind<<endl;
			x[ind].ct=sys_clk+x[ind].bt;//update CT of process
			x[ind].rbt=0;//mark process as completed
			sys_clk+=x[ind].bt;//update sys time
		}
			
		
	}
	for(int i=0; i<n; i++)
	{
		cout<<"loop that calc wt, tat runs:\n";
	  //x[i].ct=max(x[i-1].ct, x[i].at)+x[i].bt;
		x[i].tat=x[i].ct-x[i].at;
		x[i].wt=x[i].tat-x[i].bt;
	}
	disp(x);
	
	
	
}	

int main()
{
	cout<<"HRRN NPE:\n";
	process x[n];
	x[0].init(x);
	x[0].hrrn_npe(x);
	return(0);
}
