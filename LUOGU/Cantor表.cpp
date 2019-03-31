#include<iostream>
using namespace std;
int main(){
	int n,k=0,f=1,a,b;
	cin>>n;
	while(k<=n){
		k+=f;
		f++;
	}
	k=k-f;
	if(n==k){
		a=n-k;
		b=f-a;
		if((f+1)%2==0){
		cout<<a<<"/"<<b;
		return 0;
		}
		if((f+1)%2!=0){
		cout<<b<<"/"<<a;
		return 0;
		}
		return 0;
	}
/*	a=n-1-k;
	b=f-a;
	if((f+1)%2==0){
		cout<<a<<"/"<<b;
		return 0;
	}
	if((f+1)%2!=0){
		cout<<b<<"/"<<a;
		return 0;
	}*/
}
