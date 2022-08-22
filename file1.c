#include<stdio.h>
#include<string.h>

struct student{
char name[5];
int roll;
int age;
float com1,com2,com3,com4;
float GPA;
float CGPA;
};

int main()
{
int k,i;
float w,x,y,z;
printf("Enter the no of students");
scanf("%d",&k);
struct student s[5],t[3];
FILE* fd,*fe,*ff,*fg;
char *a;
for(i=0;i<k;i++){
/*printf("Enter the semester");
scanf("%d",&a);
if(a==1)
fd=fopen("sem1.txt","a+");
else if(a==2)
fd=fopen("sem2.txt","a+");
else if(a==3)
{
fd=fopen("sem3.txt","a+");
}
else
{
fd=fopen("sem4.txt","a+");
}
*/
printf("\n First Sem:\n");
fd=fopen("sem1.txt","a+");
printf("enter name");
scanf("%s",s[i].name);

printf("enter rno");
scanf("%d",&s[i].roll);
printf("enter com1,com2,com3,com4");
scanf("%f %f %f %f",&s[i].com1,&s[i].com2,&s[i].com3,&s[i].com4);
s[i].GPA=(s[i].com1+s[i].com2+s[i].com3+s[i].com4)/4.0;
s[i].CGPA=s[i].GPA;
fprintf(fd,"%s %d %f %f %f %f %f %f",s[i].name,s[i].roll,s[i].com1,s[i].com2,s[i].com3,s[i].com4,s[i].GPA,s[i].CGPA);
if(s[i].com1==9)
printf("com1");
if(s[i].com2==9)
printf("com2");
if(s[i].com3==9)
printf("com3");
if(s[i].com4==9)
printf("com4");
/*printf("%s %d %f %f %f %f %f %f",s[i].name,s[i].roll,s[i].com1,s[i].com2,s[i].com3,s[i].com4,s[i].GPA,s[i].CGPA);*/
fclose(fd);

printf("\n Second Sem:\n");
fd=fopen("sem1.txt","r");
fe=fopen("sem2.txt","a+");

printf("enter com1,com2,com3,com4");
scanf("%f %f %f %f",&s[i].com1,&s[i].com2,&s[i].com3,&s[i].com4);
s[i].GPA=(s[i].com1+s[i].com2+s[i].com3+s[i].com4)/4;

fscanf(fd,"%s %d %f %f %f %f %f %f",t[0].name,&t[0].roll,&t[0].com1,&t[0].com2,&t[0].com3,&t[0].com4,&t[0].GPA,&t[0].CGPA);
s[i].CGPA=(s[i].GPA+t[0].GPA)/2;

fprintf(fe,"%s %d %f %f %f %f %f %f",s[i].name,s[i].roll,s[i].com1,s[i].com2,s[i].com3,s[i].com4,s[i].GPA,s[i].CGPA);

if(s[i].com1==9)
printf("com1");
if(s[i].com2==9)
printf("com2");
if(s[i].com3==9)
printf("com3");
if(s[i].com4==9)
printf("com4");

/*printf("%s %d %f %f %f %f %f %f",s[i].name,s[i].roll,s[i].com1,s[i].com2,s[i].com3,s[i].com4,s[i].GPA,s[i].CGPA);*/
fclose(fd);
fclose(fe);

printf("\n Third Sem:\n");
fd=fopen("sem1.txt","r");
fe=fopen("sem2.txt","r");
ff=fopen("sem3.txt","a+");

printf("enter com1,com2,com3,com4");
scanf("%f %f %f %f",&s[i].com1,&s[i].com2,&s[i].com3,&s[i].com4);
s[i].GPA=(s[i].com1+s[i].com2+s[i].com3+s[i].com4)/4;
fscanf(fe,"%s %d %f %f %f %f %f %f",t[1].name,&t[1].roll,&t[1].com1,&t[1].com2,&t[1].com3,&t[1].com4,&t[1].GPA,&t[1].CGPA);
s[i].CGPA=(s[i].GPA+t[0].GPA+t[1].GPA)/3;
fprintf(ff,"%s %d %f %f %f %f %f %f",s[i].name,s[i].roll,s[i].com1,s[i].com2,s[i].com3,s[i].com4,s[i].GPA,s[i].CGPA);

if(s[i].com1==9)
printf("com1");
if(s[i].com2==9)
printf("com2");
if(s[i].com3==9)
printf("com3");
if(s[i].com4==9)
printf("com4");

/*printf("%s %d %f %f %f %f %f %f",s[i].name,s[i].roll,s[i].com1,s[i].com2,s[i].com3,s[i].com4,s[i].GPA,s[i].CGPA);*/
fclose(fd);
fclose(fe);
fclose(ff);

printf("\n Fourth Sem:\n");
fd=fopen("sem1.txt","r");
fe=fopen("sem2.txt","r");
ff=fopen("sem3.txt","r");
fg=fopen("sem4.txt","a+");

printf("enter com1,com2,com3,com4");
scanf("%f %f %f %f",&s[i].com1,&s[i].com2,&s[i].com3,&s[i].com4);
s[i].GPA=(s[i].com1+s[i].com2+s[i].com3+s[i].com4)/4;

fscanf(ff,"%s %d %f %f %f %f %f %f",t[2].name,&t[2].roll,&t[2].com1,&t[2].com2,&t[2].com3,&t[2].com4,&t[2].GPA,&t[2].CGPA);
s[i].CGPA=(s[i].GPA+t[0].GPA+t[1].GPA+t[2].GPA)/4;

fprintf(fg,"%s %d %f %f %f %f %f %f",s[i].name,s[i].roll,s[i].com1,s[i].com2,s[i].com3,s[i].com4,s[i].GPA,s[i].CGPA);

if(s[i].com1==9)
printf("com1");
if(s[i].com2==9)
printf("com2");
if(s[i].com3==9)
printf("com3");
if(s[i].com4==9)
printf("com4");

/*printf("%s %d %f %f %f %f %f %f",s[i].name,s[i].roll,s[i].com1,s[i].com2,s[i].com3,s[i].com4,s[i].GPA,s[i].CGPA);*/
fclose(fd);
fclose(fe);
fclose(ff);
fclose(fg);

printf("CGPA >= 7.5  : ");
fd=fopen("sem1.txt","r");
fe=fopen("sem2.txt","r");
ff=fopen("sem3.txt","r");
fg=fopen("sem4.txt","r");
if(s[i].CGPA >= 7.5)
printf("%s %d %f",s[i].name,s[i].roll,s[i].CGPA);

a=strstr(s[i].name,"ra");
//printf("Substring %s",a);
if(a!=NULL)
{
printf("%s",s[i].name);
}
}
printf("Enter the semester to check for s grade");


return (0);
}



