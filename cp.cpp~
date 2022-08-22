#include<iostream>
using namespace std;
#include<cstdlib>
#include<unistd.h>
#include<ctype.h>
#include<fcntl.h>
#define bs 20
int main(){
int fd[2];


pid_t pid;

if(pipe(fd)==0)
pid=fork();              

int fin=open("InputFile.txt",O_RDONLY);
int fo=open("OutputCopy.txt",O_WRONLY);
if(pid==0){
close(fd[0]);
char fi[bs];
int r=0;
while((r=read(fin,fi,bs))>0){
write(fd[1],fi,r);
}
close(fd[1]);
close(fin);
}
else if(pid>0){
close(fd[1]);
int count=0;
char m[bs];
while((count=read(fd[0],m,bs))>0){
write(fo,m,count);
}
close(fd[0]);
close(fo);
}



return 0;
}
