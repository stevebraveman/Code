#include<iostream>
using namespace std;
int main(){
	long long n,f1=0,f2=1,t;
	cin>>n;
	for(int i=2;i<=n;i++){
		t=f2;
		f2=f1+f2;
		f1=t;
	}
	cout<<f2;
}

