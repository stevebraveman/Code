#include<iostream>
using namespace std;
int main(){
	int n,maxa=0,t=1;
	cin>>n;
	int a[n+2];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>a[i-1]){
			t++;
			if(maxa<t) maxa=t;
		}
		else t=1;
	}
	cout<<maxa;
}
