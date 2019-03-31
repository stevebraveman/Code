#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	int n,a[10001],maxa=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int tot=1;
		int t=i;
		while((a[t]+1)==a[t+1]){
			tot++;
			t++;
		}
		if(maxa<tot) maxa=tot;
	}
	cout<<maxa;
}
