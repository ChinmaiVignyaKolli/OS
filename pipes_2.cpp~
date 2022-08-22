#include<iostream>
using namespace std;
#include<unistd.h>
#include<cstdlib>

int main(){
pid_t pid;
int fd1[2];
int fd2[2];
pipe(fd1);
pipe(fd2);
char str[20];
char str1[20];
pid=fork();

if(pid>0){

cout<<"Enter String1 to Send "<<endl;
cin>>str;
write(fd1[1],&str,20);
read(fd2[0],&str1,20);
cout<<str1<<"Received at parent"<<endl;
}
else if(pid==0){
read(fd1[0],&str,20);
cout<<"Enter string2"<<endl;
cin>>str1;

cout<<str<<"Received at child"<<endl;

write(fd2[1],&str1,20);

}
return 0;
}
