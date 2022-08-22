#include<iostream>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<cstdlib>
using namespace std;

int main(){
pid_t pid;
int n,i,e;
int status;
cout<<"Enter a range";
cin>>i;
cin>>e;


pid=vfork();

if(pid==0){
int x=i;
while(x<=e){
int y=0;
for(int k=1;k<x;k++){
	if(x%k==0){
	y+=k;
	}

}
if(y==x){
cout<<x<<"is a perfect number"<<endl;
}

x++;
}
if(x==e){
cout<<x;
}
exit(0);
}
else{
pid=wait(&status);
cout<<"Parent process";
}
return 0;











}
