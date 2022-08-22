#include<iostream>
using namespace std;
#include<cstdlib>
#include<unistd.h>
#include<ctype.h>
int main(){
int fd[2];
int n;
char str[20];
pid_t pid;
pipe(fd);
pid=fork();

if(pid==0){
dup2(fd[1],1);
execlp("ls","ls","-a",NULL);
}
else if(pid>0){
close(fd[1]);

	while((n=read(fd[0],&str,20))>0){
		for(int i=0;i<n;i++){
		str[i]=toupper(str[i]);
		
		}
	write(1,str,n);
	}
}

return 0;
}

