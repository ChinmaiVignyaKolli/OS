#include<iostream>
#include<cstdarg>
#include<vector>
using namespace std;

template <class T>
class sorting{

private:
vector <T> elems;
public:
va_list sort(int,...);
};


template <class T>
va_list sorting<T>::sort(int count,...){
float sum=0;
va_list list;
va_start(list,count);
T temp;
for(int i=0;i<count;i++){
	for(int j=0;j<n-i-1;j++){
	if(va_arg[j]>va_arg[j+1]){
 		temp=va_arg[j];
		
		va_arg[j]=va_arg[j+1];

		va_arg[j+1]=temp;
		

	}


	}
}
return(list);
}


int main(){

sorting<int> intSort;
int a[5];

 a[]=intSort.sort(5,1,2,3,4,5);
//std::cout<<sort(5,1,2,3,4,5)<<'\n';
}













