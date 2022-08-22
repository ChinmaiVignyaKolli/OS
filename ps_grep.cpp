#include<iostream>
using namespace std;
#include<cstdlib>
#include<unistd.h>
#include<ctype.h>
int main(){
int fd[2];
int fd1[2];
int n;
char str[20];
pid_t pid;

if(pipe(fd)==0)
pid=fork();

//char *arg[]={"ps","-a",NULL};
if(pid==0){
dup2(fd[1],1);
execlp("ps","ps",NULL);
//close(fd[1]);
}
else if(pid>0){
close(fd[1]);
dup2(fd[0],0);
execlp("grep","grep","bash",NULL);

}
return 0;
}
