#include<iostream>
using namespace std;
int gcd(int x){
int t=0;
for(int i=1;i<=x/2;i++){
	if(x%i==0) t=t+i;
	}
	return t;
}
int main(){
	int n,a;
	cin>>n;
	for(a=n;a;a++){
	if(gcd(a)!=gcd(gcd(a)) && gcd(gcd(a))==a){
	cout<<a<<" "<<gcd(a);
	return 0;
	}
	}
	return 0;
}
