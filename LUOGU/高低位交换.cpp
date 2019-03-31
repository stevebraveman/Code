#include<iostream>
#include<cmath>
using namespace std;
bool a[100],g[100];
int main(){
	long long n,h=0;
	cin>>n;
	for(int i=31;i>=0;i--){
		if(n-pow(2,i)>=0){
			n-=pow(2,i);
			g[i]=1;
		}
		else{
			g[i]=0;
		}
	}
	for(int i=31;i>=16;i--){
		a[i-16]=g[i];
	}
	for(int i=16;i>=0;i--){
		a[i+16]=g[i];
	}
	for(int i=31;i>=0;i--){
		if(a[i]==1) h+=pow(2,i);
		else continue;
	}
	cout<<h;
}
