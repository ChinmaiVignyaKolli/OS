#include<iostream>
#include<string.h>

using namespace std;

void sort(float a[100],int n)
{
	int i,j;
	int temp;
	for(i=0;i<n;i++)
	for(j=0;j<n-i-1;j++)
	{
		if(a[j]>a[j+1])
		{
			temp=a[j+1];
			a[j+1]=a[j];
			a[j]=temp;
		}
	
	}
}

void display(float a[100],int n)
{
	for(int i=0;i<n;i++)
	cout<<a[i]<<' ';
	cout<<endl;

}

int main(int argc,char *argv[])
{
	float a[100];
	int n;
	n=atof(argv[1]);
	for(int i=0;i<n;i++)
	a[i]=atof(argv[i+2]);
	cout<<"\nBefore Sorting:\n";
	display(a,n);
	sort(a,n);
	cout<<"\nAfter Sorting:\n";
	display(a,n);
	return 0;
}
