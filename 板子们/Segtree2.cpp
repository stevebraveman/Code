#include <iostream>
#include <cstdio>
#define MAXN 100005
#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
#define ll long long
struct Segtree {
	ll lazy[MAXN << 2] , a[MAXN] , b[MAXN << 2];
	inline void pd(ll p) {
		b[p] = b[rs(p)] + b[ls(p)];
	}
	void build(ll l , ll r , ll p) {
		lazy[p] = 0;
		if (l == r) {
			b[p] = a[l];
			return;
		}
		ll m = (l + r) >> 1;
		build(l , m , ls(p));
		build(m + 1 , r , rs(p));
		pd(p);
	}
	inline void f(ll p , ll l , ll r , ll k) {
		b[p] += k * (r - l + 1);
		lazy[p] += k;
	}
	inline void pushd(ll p , ll l , ll r) {
		ll m = (l + r) >> 1;
		f(ls(p) , l , m , lazy[p]);
		f(rs(p) , m + 1 , r , lazy[p]);
		lazy[p] = 0;
	}
	void update(ll x , ll y , ll l , ll r , ll p , ll k) {
		if (x <= l && y >= r) {
			b[p] += k * (r - l + 1);
			lazy[p] += k;
			return;
		}
		pushd(p , l , r);
		ll m = (l + r) >> 1;
		if (x <= m) update(x , y , l , m , ls(p) , k);
		if (y > m) update(x , y , m + 1 , r , rs(p) , k);
		pd(p);
	}
	ll sum(ll x , ll y , ll l , ll r , ll p) {
		ll s = 0;
		if (x <= l && y >= r) {
			return b[p];
		}
		ll m = (l + r) >> 1;
		pushd(p , l , r);
		if (x <= m) s += sum(x , y , l , m , ls(p));
		if (y > m) s += sum(x , y , m + 1 , r , rs(p));
		return s;
	}
}tree;
ll n , m , l , r , k , flag;
int main() {
	scanf("%lld%lld" , &n , &m);
	for (int i = 1 ; i <= n ; i++) {
		scanf("%d" , &tree.a[i]);
	}
	tree.build(1 , n , 1);
	for (int i = 1 ; i <= m ; i++) {
		scanf("%lld" , &flag);
		if (flag == 1) {
			scanf("%lld%lld%lld" , &l , &r , &k);
			tree.update(l , r , 1 , n , 1 , k);
		}
		else {
			scanf("%lld%lld" , &l , &r);
			printf("%lld\n" , tree.sum(l , r , 1 , n , 1));
		}
	}
	return 0;
}
