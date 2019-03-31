#include<iostream>
using namespace std;
int gcd(long long a,long long b){
	return b==0?a:gcd(b,a%b);
}
int main(){
	long long m,n;
	cin>>m>>n; 
	cout<<gcd(m,n);
}
