#include<iostream>
using namespace std;
int main(){
	int n,a[101];
	cin>>n;
	int ave=0,step=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];ave+=a[i];
	}
	ave/=n;
	for(int i=1;i<=n;i++) a[i]-=ave;
	int j=n;
	int i=1;
	while(a[i]==0&&i<n) i++;
	while(a[j]==0&&j>1) j--;
	while(i<j){
		a[i+1]+=a[i];
		a[i]=0;
		step++;
		i++;
		while(a[i]==0&&i<j) i++;
	}
	cout<<step;
}
