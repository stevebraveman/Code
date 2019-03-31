#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#define ll long long
#define lson num<<1,l,mid
#define rson num<<1|1,mid+1,r
using namespace std;
const ll maxn=200010;
ll n,m;
ll tree[maxn<<2],treemin[maxn<<2],lazy[maxn<<2],a[maxn];
ll min(ll a,ll b){
	return a<b?a:b;
}
void push_up(ll num) {
	tree[num]=tree[num<<1]+tree[num<<1|1];
	treemin[num]=min(treemin[num<<1],treemin[num<<1|1]);
}
void push_down(ll num,ll len) {
	tree[num<<1]+=lazy[num]*(len-(len>>1));
	treemin[num<<1]+=lazy[num];
	lazy[num<<1]+=lazy[num];
	tree[num<<1|1]+=lazy[num]*(len>>1);
	treemin[num<<1|1]+=lazy[num];
	lazy[num<<1|1]+=lazy[num];
	lazy[num]=0;
}
void build(ll num,ll l,ll r) {
	if(l==r) {
		tree[num]=treemin[num]=a[l];
		return;
	}
	ll mid=(l+r)>>1;
	build(lson);
	build(rson);
	push_up(num);
	return;
}
void update(ll L,ll R,ll delta,ll num,ll l,ll r) {
	if(L<=l&&r<=R) {
		tree[num]+=delta*(r-l+1);
		treemin[num]+=delta;
		lazy[num]+=delta;
		return ;
	}
	if(lazy[num]) push_down(num,r-l+1);
	ll mid=(l+r)>>1;
	if(L<=mid) update(L,R,delta,lson);
	if(R>mid) update(L,R,delta,rson);
	push_up(num);
	return;
}
ll query_min(ll L,ll R,ll num,ll l,ll r) {
	if(L<=l&&r<=R) {
		return treemin[num];
	}
	if(lazy[num]) push_down(num,r-l+1);
	ll mid=(r+l)>>1,ret=0x3f3f3f3f;
	if(L<=mid) ret=min(ret,query_min(L,R,lson));
	if(R>mid) ret=min(ret,query_min(L,R,rson));
	return ret;
}
ll query(ll L,ll R,ll num,ll l,ll r) {
	if(L<=l&&r<=R) {
		return tree[num];
	}
	if(lazy[num]) push_down(num,r-l+1);
	ll mid=(l+r)>>1,ret=0;
	if(L<=mid) ret+=query(L,R,lson);
	if(R>mid) ret+=query(L,R,rson);
	return ret;
}
int main() {
	ll n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		scanf("%lld",&a[i]);
	}
	build(1,1,n);
	for(int i=1; i<=m; i++) {
		char c;
		ll x,y,z;
		cin>>c;
		if(c=='M') {
			scanf("%lld%lld",&x,&y);
			printf("%lld\n",query_min(x,y,1,1,n));
		}
		if(c=='S') {
			scanf("%lld%lld",&x,&y);
			printf("%lld\n",query(x,y,1,1,n));
		}
		if(c=='P') {
			scanf("%lld%lld%lld",&x,&y,&z);
			update(x,y,z,1,1,n);
		}
	}
	return 0;
}
