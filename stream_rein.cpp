#include<iostream>
using namespace std;
#include<cstdlib>
#include<unistd.h>
#include<ctype.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(){
int n;
int fp;
char str[20];
pid_t pid;
fp=open("indirect.txt",O_WRONLY|O_CREAT,0666);

pid=fork();


if(pid>0){
dup2(fp,1);
execlp("ls","ls",NULL);


}
else if(pid==0){

int fd = dup2(fp,0);
  while((n=read(fd,&str,20))>0){
		
	write(1,str,n);
	}

}
return 0;
}
