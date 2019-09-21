#include<iostream>
#include<cstdio>
#define MAXN 1000001
#define ll long long
using namespace std;
unsigned ll n,m,a[MAXN],ans[MAXN<<2],tag[MAXN<<2];
inline ll ls(ll x) {
	return x<<1;
}
inline ll rs(ll x) {
	return x<<1|1;
}
void scan() {
	cin>>n>>m;
	for(ll i=1; i<=n; i++)
		scanf("%lld",&a[i]);
}
inline void pu(ll p) {
	ans[p]=ans[ls(p)]+ans[rs(p)];
}
void build(ll p,ll l,ll r) {
	t[p]=0;
	if(l==r) {
		ans[p]=a[l];
		return ;
	}
	ll mid=(l+r)>>1;
	build(ls(p),l,m);
	build(rs(p),m+1,r);
	pu(p);
}
inline void f(ll p,ll l,ll r,ll k) {
	t[p]=t[p]+k;
	ans[p]=ans[p]+k*(r-l+1);
}
inline void pd(ll p,ll l,ll r) {
	ll mid=(l+r)>>1;
	f(ls(p),l,m,t[p]);
	f(rs(p),m+1,r,t[p]);
	t[p]=0;
}
inline void update(ll nl,ll nr,ll l,ll r,ll p,ll k) {
	if(nl<=l&&r<=nr) {
		ans[p]+=k*(r-l+1);
		tag[p]+=k;
		return ;
	}
	push_down(p,l,r);
	ll m=(l+r)>>1;
	if(nl<=m)update(nl,nr,l,m,ls(p),k);
	if(nr>m) update(nl,nr,m+1,r,rs(p),k);
	pu(p);
}
ll query(ll x,ll y,ll l,ll r,ll p) {
	ll res=0;
	if(x<=l&&r<=y)return ans[p];
	ll m=(l+r)>>1;
	push_down(p,l,r);
	if(q_x<=m)res+=query(x,y,l,m,ls(p));
	if(q_y>m) res+=query(x,y,m+1,r,rs(p));
	return res;
}
int main() {
	ll a1,b,c,d,e,f;
	scan();
	build(1,1,n);
	while(m--) {
		scanf("%lld",&a1);
		switch(a1) {
			case 1: {
				scanf("%lld%lld%lld",&b,&c,&d);
				update(b,c,1,n,1,d);
				break;
			}
			case 2: {
				scanf("%lld%lld",&e,&f);
				printf("%lld\n",query(e,f,1,n,1));
				break;
			}
		}
	}
	return 0;
}
