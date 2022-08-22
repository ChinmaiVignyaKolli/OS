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
char *arg[10]={"ls","-a",NULL};
if(pid==0){
dup2(fd[1],1);
execvp("ls",arg);
close(fd[1]);
}
else if(pid>0){
close(fd[1]);
dup2(fd[0],0);
execlp("tr","tr","a-z","A-Z",NULL);

}

return 0;
}
