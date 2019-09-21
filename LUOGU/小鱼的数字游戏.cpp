#include<iostream>
using namespace std;
int main(){
	int a[100],i=0;
	do{
		++i;
		cin>>a[i];
	}while(a[i]!=0); 
	for(int j=i-1;j>=1;j--){
		cout<<a[j]<<" ";
	}
	return 0;
}
