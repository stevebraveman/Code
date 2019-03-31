#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
#define MAX 1000005
#define il inline
#define ls(x) ((x)<<1)
#define rs(x) ((x)<<1|1)
using namespace std;
struct segment_tree {
	ll a[MAX],b[MAX<<2],lazy[MAX<<2];
	il void pd(ll p) {
		b[p]=b[ls(p)]+b[rs(p)];
	}
	void build_tree(ll l,ll r,ll p) {
		lazy[p]=0;
		if(l==r) {
			b[p]=a[l];
			return;
		}
		ll m=(l+r)>>1;
		build_tree(l,m,ls(p));
		build_tree(m+1,r,rs(p));
		pd(p);
	}
	il void f(ll p,ll l,ll r,ll k) {
		b[p]=b[p]+k*(r-l+1);
		lazy[p]=lazy[p]+k;
	}
	il void p_d(ll p,ll l,ll r) {
		ll m=(l+r)>>1;
		f(ls(p),l,m,lazy[p]);
		f(rs(p),m+1,r,lazy[p]);
		lazy[p]=0;
	}
	il void ud(ll x,ll y,ll l,ll r,ll p,ll k) {
		if(x<=l&&y>=r) {
			b[p]+=k*(r-l+1);
			lazy[p]+=k;
			return;
		}
		p_d(p,l,r);
		ll m=(l+r)>>1;
		if(x<=m) ud(x,y,l,m,ls(p),k);
		if(y>m) ud(x,y,m+1,r,rs(p),k);
		pd(p);
	}
	ll sum(ll x,ll y,ll l,ll r,ll p) {
		ll s=0;
		if(x<=l&&y>=r) {
			return b[p];
		}
		ll m=(l+r)>>1;
		p_d(p,l,r);
		if(x<=m)s+=sum(x,y,l,m,ls(p));
		if(y>m) s+=sum(x,y,m+1,r,rs(p));
		return s;
	}
}tree;

int main() {
	ll n,m,c,d,e,f,g,h;
	cin>>n>>m;
	for(ll i=1; i<=n; i++) {
		scanf("%lld",&tree.a[i]);
	}
	tree.build_tree(1,n,1);
	for(ll i=1; i<=m; i++) {
		scanf("%lld",&c);
		if(c==1) {
			scanf("%lld%lld%lld",&d,&e,&f);
			tree.ud(d,e,1,n,1,f);
		} else {
			scanf("%lld%lld",&g,&h);
			printf("%lld\n",tree.sum(g,h,1,n,1));
		}
	}
	return 0;
}
