#include<iostream>
using namespace std;
#include<cstdlib>
#include<unistd.h>
int main(){
int fd[2];
char str[20];
pid_t pid;
pipe(fd);
pid=fork();

if(pid>0){
close(fd[0]);
cout<<"Enter string to send";
cin>>str;
write(fd[1],&str,20);
cout<<str<<" message sent"<<endl;
}
else if(pid==0){
close(fd[1]);
read(fd[0],&str,20);
cout<<str<<" Received";
}
return 0;
}
