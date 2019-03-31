#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int n,a[20001],temp;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i;j++){
			if(a[i]==a[i+j]) a[i+j]=0;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=0){
			for(int i=1;i<=n-1;i++){
		for(int j=1;j<=n-i;j++){
			if(a[j]>a[j+1]){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}		
	}
	for(int i=1;i<=n;i++)
	printf("%d ",a[i]);
	return 0;
		}
	}
	return 0;
}
