#include<iostream>
#include<cstdio>
#include<cstring>
#define MAXN 1000001
#define ll long long
using namespace std;
unsigned ll n,m,a[MAXN],ans[MAXN<<2],t[MAXN<<2];
ll max(int a,int b){
	return a>b?a:b;
}
inline ll ls(ll x) {
	return x<<1;
}
inline ll rs(ll x) {
	return x<<1|1;
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
ll query(ll x,ll y,ll l,ll r,ll p) {
	ll res=0;
	if(x<=l&&r<=y)return ans[p];
	ll m=(l+r)>>1;
	pd(p,l,r);
	if(x<=m)res+=query(x,y,l,m,ls(p));
	if(y>m) res+=query(x,y,m+1,r,rs(p));
	return res;
}
int main() {
	ll a1,b,c,d,e,f,t;
	memset(ans,0,sizeof(ans));
	cin>>n>>m;
	ll k;
	for(ll i=1; i<=n; i++) {
		scanf("%lld",&k);
		scanf("%lld",&a[k]);
		t=max(t,a[k]);
	}
	build(1,1,t);
	ll maxl=0;
	for(int i=1;i<=t-m+1;i++){
		ll q=query(i,i+m-1,1,t,1);
		maxl=max(q,maxl);
	}
	printf("%lld\n",maxl);
	return 0;
}
