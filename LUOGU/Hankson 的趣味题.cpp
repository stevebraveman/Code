#include<iostream>
#include<cmath>
#include<cstdio>
#define ll long long
using namespace std;
ll gcd(ll x,ll y) {
	if (y == 0) return x;
	else return gcd(y , x % y);
}
inline ll lcm(ll x,ll y) {
	return (x * y) / gcd(x,y);
}
int main() {
	int n;
	ll a0,a1,b0,b1;
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		int tot=0;
		scanf("%lld%lld%lld%lld",&a0,&a1,&b0,&b1);
		for(int x=1; x*x<=b1; x++) {
			if(b1%x==0) {
				if(gcd(x,a0)==a1&&lcm(x,b0)==b1) tot++;
				if(b1/x!=x) {
					if(gcd(b1/x,a0)==a1&&lcm(b1/x,b0)==b1) tot++;
				}
			}
		}
		printf("%d\n",tot);
	}
}