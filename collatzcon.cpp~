#include<iostream>
#include<sys/types.h>
#include<cstdlib>
#include<sys/wait.h>
#include<unistd.h>
#include<cstdio>
using namespace std;

int main(){
pid_t pid;
int n;
cout<<"Enter a number";
cin>>n;

pid=fork();


	if(pid==0){
		while(n!=1)
			if(n%2==0){
				while(n!=1 && n%2==0){
				n=n/2;
				cout<<n<<endl;
				}
				if(n==1){
				cout<<"1 reached"<<endl;		
				}
				
			}

			else if(n%2==1){
				while(n!=1 && n%2==1){
				n=3*n+1;
				cout<<n<<endl;
				}
				if(n==1){
				cout<<"1 reached"<<endl;		
				}
				
			}
		}
	

	else{
		wait(NULL);
		cout<<"Collatz conjuction printed";
	}



return 0;
}
