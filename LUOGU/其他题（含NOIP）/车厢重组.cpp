#include<iostream>
#include<cstdio> 
using namespace std;
int a[10001];
int main(){
	int n,temp,tot=0;
	cin>>n; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-1;i++){
		int m=1;
		for(int j=1;j<=n-i;j++){
			if(a[j]>a[j+1]){
				m=0;
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				tot++;
			}
		}
		if(m==1) break;
	}
	cout<<tot;
}
