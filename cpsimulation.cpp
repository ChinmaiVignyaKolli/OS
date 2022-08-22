//shell simulation

#include<iostream>
#include<stdlib.h>
#include <bits/stdc++.h>
#include<sys/types.h>
#include<unistd.h>
#include<wait.h>
using namespace std;
int main()
{
  pid_t pid;
  pid = vfork();
  char command[100],str[100];
  int ch=1,k;

  FILE * fp;
  
  if(pid == 0)
    {

    
      cout<<"Enter the command you want to execute"<<endl;
      cin.getline(command,sizeof(command));//reads the total line
       
      fp= fopen("commsim.txt","a");
      fprintf(fp, "%s \n",command);
      fclose(fp);   

      
   exit(0);
    }

  else if(pid>0)
   {
      
   //  cout<<command<<endl;
     //system(command);
   
     fp= fopen("commsim.txt","r");
     char line[256];
     int i = 0,j;
     while (fgets(line, sizeof(line), fp)) 
        i++;
    
    
   cout<<"No of lines is :"<<i<<endl;
   fclose(fp);

   fp= fopen("commsim.txt","r");
   fseek(fp,0,SEEK_CUR);
    j=i;
  cout<<"Which of the recent command you want to execute?"<<endl;
  cin>>k;
    while (fgets(line, sizeof(line), fp))
     {
        j--;
       if(j==k )
        {
            printf("%s", line); 
             system(line); 
             
        }
      
    }    
  
    exit(0);
   }
 
      

  


  
return 0; 
   
}
