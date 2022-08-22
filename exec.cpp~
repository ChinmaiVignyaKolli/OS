#include<iostream>
using namespace std;
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<cstdlib>

int main(){
pid_t pid;
pid = fork();

if(pid==0){
wait(NULL);
cout<<"The child is an orphan"<<endl;
}
if(pid>0){
exit(0);
}

return 0;
}



