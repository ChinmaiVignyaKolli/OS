#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<string.h>
int main(){
pid_t pid;
FILE *fd;
int i,words=0;
char comm[50];

fd=fopen("cpsim.txt","a");
printf("Enter commands");
scanf("%s",comm);
pid = fork();

if(pid==0){
fprintf(fd,"%s",comm);
for(i=0;i<strlen(comm);i++){
printf("%d",strlen(comm));
if(comm[i]==' '){
words++;
}

}
printf("%d",words);
}
return 0;
}
