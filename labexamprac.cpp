#include<iostream>
using namespace std;
#include<unistd.h>
#include<cstdlib>
#include<sys/wait.h>
#include<sys/types.h>
#include<cstring>
int n;
int main(){

pid_t pid;
int fd1[2],fd2[2];
pipe(fd1);
pipe(fd2);
string str;
pid=fork();

if(pid>0){
cout<<"Enter string to send";
cin>>str;
close(fd1[0]);
write(fd1[1],&str,20);
 wait(NULL);
close(fd2[1]);
read(fd2[0],&str,n);
cout<<str<<"received at child";

}

else if(pid==0){
while((n=read(fd1[0],&str,20))>0){
int i;
for(i=0;i<n;i++){
if((int)str[i]>=65 && (int)str[i]<=90)
{
str[i]=tolower(str[i]);
}
if((int)str[i]>=97 && (int)str[i]<=122)
{
str[i]=toupper(str[i]);

}
}

}
write(1,&str,n);
close(fd2[1]);
close(fd1[0]);
exit(0);
}


return 0;
}
