#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstring>
#define ll long long
#define MAXN 2000005
#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
struct Segtree {
	ll a[MAXN] , b[MAXN << 2] , lazy[MAXN << 2];
	inline void pd(ll p) {
		b[p] = b[ls(p)] + b[rs(p)];
	}
	void build(ll l , ll r , ll p) {
		if (l == r) {
			b[p] = a[l];
			return;
		}
		ll m = (l + r) >> 1;
		build(l , m , ls(p));
		build(m + 1 , r , rs(p));
		pd(p);
	}
	inline void pushd(ll p , ll l) {
		if (lazy[p]) {
			lazy[ls(p)] ^= 1;
			lazy[rs(p)] ^= 1;
			b[ls(p)] = (l - (l >> 1)) - b[ls(p)];
			b[rs(p)] = (l >> 1) - b[rs(p)];
			lazy[p] = 0;
		}
	}
	void up(ll x , ll y , ll l , ll r , ll p) {
		pushd(p , r - l + 1);
		if (x <= l && y >= r) {
			lazy[p] ^= 1;
			b[p] = r - l + 1 - b[p];
			return;
		}
		ll m = (l + r) >> 1;
		if (x <= m) up(x , y , l , m , ls(p));
		if (y > m) up(x , y , m + 1 , r , rs(p));
		pd(p);
	}
	ll sum(ll x , ll y , ll l , ll r , ll p) {
		ll s = 0;
		if (x <= l && y >= r) {
			return b[p];
		}
		pushd(p , r - l + 1);
		ll m = (l + r) >> 1;
		if (x <= m) s += sum(x , y , l , m , ls(p));
		if (y > m) s += sum(x , y , m + 1 , r , rs(p));
		return s;
	}
}tree;
ll n , m , l , r , k;
char s;
int main() {
	scanf("%lld%lld" , &n , &m);
	tree.build(1 , n , 1);
	while (m--) {
		scanf("%lld%lld%lld" , &k , &l , &r);
		if (k == 0) {
			tree.up(l , r , 1 , n , 1);
		}
		else {
			printf("%lld\n" , tree.sum(l , r , 1 , n , 1));
		}
	}
}
