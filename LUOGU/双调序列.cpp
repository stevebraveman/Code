#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	long n,a[1001],b[1001];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(a,a+n);
	sort(b,b+n,cmp);
	int j=1,p=0,q=1;
	while(j<=n){
		if(j%2!=0) cout<<b[j]<<endl;
		if(j%2==0) cout<<a[j/2]<<endl;
		
		j++;
	}
	return 0;
}
