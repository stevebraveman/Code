#include<iostream>
using namespace std;
int main(){
	long long x,n,k=1;
	cin>>x>>n;
	for(int i=1;i<=n;i++) k=k*(x+1);
	cout<<k;
}
