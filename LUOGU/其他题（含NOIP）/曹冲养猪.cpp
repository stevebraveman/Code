#include<cstdio>
#define ll long long
ll x,m,M,r,y,z;
ll gcd(ll a,ll b) {
	return a%b==0 ? b:gcd(b,a%b);
}
void inv(ll a,ll b) {
	if (a%b==0) {
		z=0;
		y=1;
		return;
	}
	inv(b,a%b);
	ll r=z;
	z=y,y=r-a/b*y;
}
int main() {
	int n;
	scanf("%d",&n);
	x=0;
	m=1;
	for (int i=1; i<=n; i++) {
		scanf("%lld%lld",&M,&r);
		ll b=r-x,d=gcd(m,M);
		if (b%d!=0) {
			printf("-1");
			return 0;
		}
		inv(m/d,M/d);
		ll t=b/d*z%(M/d);
		x=x+m*t;
		m*=M/d;
	}
	printf("%lld\n\n",x>0 ? x:x+m);
	return 0;
}
