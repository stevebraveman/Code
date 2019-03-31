#include<cstdio>
#define ll long long
void gcd(ll a,ll b,ll &d,ll &x,ll &y) {
	if(b==0) {
		d=a;
		x=1,y=0;
	} else {
		gcd(b,a%b,d,y,x);
		y-=(a/b)*x;
	}
}
ll mlt(ll a,ll b,ll m) {
	ll ans=0;
	while(b) {
		if(b&1) (ans+=a) %= m;
		(a=a*2) %= m;
		b/=2;
	}
	return ans;
}
ll China(int n,ll m[],ll a[]) {
	ll M=1,d,y,x=0;
	for(int i=1; i<=n; i++) {
		M*=m[i];
	}
	for(int i=1; i<=n; i++) {
		ll w=M/m[i];
		gcd(m[i],w,d,d,y);
		x=(x+mlt(y,mlt(w,a[i],M),M))%M;
	}
	return (x+M)%M;
}
ll m[15],a[15];
int main() {
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		scanf("%lld",&a[i]);
	}
	for(int i=1; i<=n; i++) {
		scanf("%lld",&m[i]);
	}
	printf("%lld",China(n,m,a));
}
