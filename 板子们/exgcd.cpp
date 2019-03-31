#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 1000005;
typedef long long LL;
LL ex_gcd(LL a,LL b,LL &x,LL &y) {
	if(b==0) {
		x=1;
		y=0;
		return a;
	}
	LL r=ex_gcd(b,a%b,x,y);
	LL t=x;
	x=y;
	y=t-a/b*y;
	return r;
}
int main() {
	LL i,n,a1,r1,a2,r2,ans,a,b,c,d,x0,y0;
	while(scanf("%lld",&n)!=EOF) {
		bool flag=1;
		scanf("%lld%lld",&a1,&r1);
		for(i=1; i<n; i++) {
			scanf("%lld%lld",&a2,&r2);
			a=a1;
			b=a2;
			c=r2-r1;
			LL d=ex_gcd(a,b,x0,y0);
			if(c%d!=0) {
				flag=0;
			}
			int t=b/d;
			x0=(x0*(c/d)%t+t)%t;//保证x0为正
			r1=a1*x0 + r1;
			a1=a1*(a2/d);
		}
		if(!flag) {
			puts("-1");
			continue;
		}
		printf("%lld\n",r1);
	}
	return 0;
}
