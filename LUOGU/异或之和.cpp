#include<iostream>
using namespace std;
int main(){
	unsigned long long n,p;
	cin>>n;
	p=n;
	n%=4;
	if(n==1){
		cout<<1;
		return 0;
	}
	if(n==2){
		cout<<p+1;
		return 0;
	}
	if(n==3){
		cout<<0;
		return 0;
	}
	if(n==0){
		cout<<p;
		return 0;
	}
}
