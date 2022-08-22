#include<iostream>
using namespace std;
#include<unistd.h>
#include<cstdlib>
#include<string.h>
int main(){
pid_t pid;
int n;
int fd1[2];
int fd2[2];
pipe(fd1);
pipe(fd2);
char str[20];

pid=fork();

if(pid>0){

cout<<"Enter String1 to Send "<<endl;
cin>>str;
write(fd1[1],&str,20);

int n=read(fd2[0],&str,20);

cout<<n<<" Received at parent"<<endl;

}
else if(pid==0){
while((n=read(fd1[0],&str,20))>0){
cout<<n<<endl;
	for(int i=0;i<n;i++){
		  if((int)str[i]<=90 && (int)str[i]>=65){
		     str[i]=tolower(str[i]);

		 }
		else if((int)str[i]<=122 && (int)str[i]>=97){
		   str[i]=toupper(str[i]);
		}
		else {
			str[i]=str[i];
		}

		
	}

write(fd2[1],&str,20);
}

}
return 0;
}
