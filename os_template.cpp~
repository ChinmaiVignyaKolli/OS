#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int i,j;

template <class T>
void BubbleSort(T a[], int n)
{
	for (i=0; i<n-1; i++)
	{
		for (int j=0;j<n-i-1;j++)
		{
			if (a[j]>a[j+1])
			{
				T temp;
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
				}
		}
	}

	cout<<"\nAfter Sorting:\n";
	for(i=0;i<n;i++)
	cout<<a[i]<<' ';
	cout<<endl;
}

int main()
{
	float a[30];
	string b[30];
	int n,ch;
	while(1)
	{
		cout<<"\n1.Numeric Array\n2.Character Array\n3.Exit\n";
		cin>>ch;
		if(ch==1 || ch==2)
		{
			cout<<"\nEnter size: ";
			cin>>n;
		}
		switch(ch)
		{
			case 1: cout<<"\nEnter elements: ";
					for (i=0; i<n; i++)
					cin>>a[i];
					cout<<"\nBefore Sorting:\n";
					for(i=0;i<n;i++)
					cout<<a[i]<<' ';
					cout<<endl;
					BubbleSort(a,n);
					break;
			case 2: cout<<"\nEnter elements: ";
					for (i=0; i<n; i++)
					cin>>b[i];
					cout<<"\nBefore Sorting:\n";
					for(i=0;i<n;i++)
					cout<<b[i]<<' ';
					cout<<endl;
					BubbleSort(b,n);
					break;
			case 3: break;
		}
	}
	return 0;
}
