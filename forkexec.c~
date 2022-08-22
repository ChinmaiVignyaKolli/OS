#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<unistd.h>


int main(){
pid_t pid;
char *cmd[]={"ls","-l",NULL};
pid=fork();

	if(pid<0){
	fprintf(stderr,"Error in fork call");
	}
	else if(pid==0){
	//execlp("/bin/ls","ls","-a",NULL);
	execl("/bin/ls",cmd);
	//execp("a.out");
	//execv("ls",cmd);
	}

	else{
	wait(NULL);
	}
return 0;
}
