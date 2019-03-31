#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int n,a,b=0,maxa=-0x7ffffff;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		b+=a;
			if(b<a) b=a;
		if(maxa<b){
			maxa=b;
		}
	}
	cout<<maxa;
}
