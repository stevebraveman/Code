#include<iostream>
using namespace std;
int gcd(int,int);
int lcm(int,int);
int main(){
	int T,x,k=0;
	cin>>T;
	int a[T+2];
	for(int i=1;i<=T;i++){
		cin>>x;
		k=0;
		for(int j=1;j<=x;j++){
			k+=lcm(j,x);
		}
		a[i]=k;
	}
	for(int i=1;i<=T;i++){
		cout<<a[i]<<endl;
	}
	return 0;
}
int gcd(int m,int n){
	int r;
	r=m%n;
	while(r!=0){
		m=n;
		n=r;
		r=m%n;
	}
	return n;
}
int lcm(int i,int j){
	return i*j/gcd(i,j);
}
