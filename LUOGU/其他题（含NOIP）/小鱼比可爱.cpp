#include<iostream>
using namespace std;
int main(){
	int a[100],n,b[100]={0},i;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	for(i=1;i<=n;i++){
		for(int j=i-1;j>=1;j--){
			if(a[i]>a[j])  b[i]++;
		}
		cout<<b[i]<<" ";
	}
}
