#include<iostream>
using namespace std;
int n,p,q,r=0,k=0;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p>>q;
		r=r+p+q-8;
		k+=r;
	}
	cout<<k;
}
