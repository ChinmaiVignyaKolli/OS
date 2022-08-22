#include<stdio.h>
#include<signal.h>
#include<unistd.h>
 
void response (int);
void response (int sig_no)

{
printf("%s is working\n",sys_siglist[sig_no]);

}
int main()
{
alarm(5);
sleep(50);
printf("Sanfoundry\n");
signal(SIGALRM,response);
return 0;
}



/*


#include<stdio.h>
#include<pthread.h>
void *fun_t(void *arg);
void *fun_t(void *arg)
{
pthread_exit("Bye");
}
int main()
{
pthread_t pt;
void *res_t;
int ret;
ret = pthread_join(pt,&res_t);
printf("%d\n",ret);
return 0;
}




/*






#include<stdio.h>
#include<pthread.h>

void *fun_t(void*arg);
void *fun_t(void*arg)
{
printf("OS \n");
pthread_exit("Exiting");

}

int main(){

pthread_t pt;
void *res_t;
if(pthread_create(&pt,NULL,fun_t,NULL)!=0)
perror("pthread_create");
if(pthread_join(pt,&res_t)!=0)
perror("pthread_join");

printf("%s \n",res_t);
return 0;
}

*/
