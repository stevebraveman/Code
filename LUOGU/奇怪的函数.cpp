#include<iostream>
#include<cstdio>
#include<cmath>
#define MAX 100000000
#define lg(x) ((x)*(log10((x)))+1)
using namespace std;
int main() {
	long long n,p,m,l=1,h=20*MAX;
	scanf("%lld",&n);
	while(l<=h) {
		m=(l+h)/2;
		if(n<=lg(m)) {
			p=m;
			h=m-1;
		} else {
			l=m+1;
		}
	}
	cout<<p<<endl;
	return 0;
}
