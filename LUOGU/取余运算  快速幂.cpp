#include<iostream>
#include<cmath>
using namespace std;
long long b,p,k,j;
int main(){
	cin>>b>>p>>k;
	j=pow(b,p);
	cout<<b<<'^'<<p<<" "<<"mod"<<" "<<k<<"="<<j%k;
}
