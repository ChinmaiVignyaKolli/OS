#include<iostream>
#include<sys/types.h>
#include<sys/wait.h>
#include<cstdlib>
#include<unistd.h>
#include<cstdio>
#include<stdint.h>
using namespace std;
int main(){
pid_t pid;
char *cmd[50]={"ls","-a",NULL};
pid=fork();

	if(pid<0){
	fprintf(stderr,"Error in fork call");
	}
	else if(pid==0){
	//execlp("/bin/ls","ls","-a",NULL);
	//execl("/bin/ls","ls","-a",NULL);
	//execvp(cmd[0],cmd);
	execv("/bin/ls","ls","-a",NULL);
	}

	else{
	wait(NULL);

	}
return 0;
}
