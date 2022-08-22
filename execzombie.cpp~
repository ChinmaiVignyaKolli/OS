#include<iostream>
using namespace std;
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<cstdlib>

int main(){
pid_t pid;
int status;
pid = fork();

if(pid==0){
cout<<"The child is a zombie ";
exit(0);

}
if(pid>0){
sleep(30);
cout<<"I am the parent";
}

return 0;
}



