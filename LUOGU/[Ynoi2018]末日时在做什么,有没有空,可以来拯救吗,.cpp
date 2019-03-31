#include <iostream>
#include <cstdio>
#define MAXN 500005
#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
#define ll long long
#define INF 19260817
inline ll max(ll a, ll b) {
	if (a > b) return a;
	else return b;
}
inline ll min(ll a, ll b) {
	if (a < b) return a;
	else return b;
}
inline void swap(ll &a, ll &b) {
	ll t = a;
	a = b;
	b = t;
}
struct tree {
	ll b, qz, hz, zd, lazy;
	void init() {
		b = -INF, qz = -INF, hz = -INF, zd = -INF;
	}
}a[MAXN << 2];
struct Segtree {
	ll c[MAXN];
	inline void pd(ll p) {
		a[p].b = a[rs(p)].b + a[ls(p)].b;
		a[p].qz = max(a[ls(p)].qz, a[ls(p)].b + a[rs(p)].qz);
		a[p].hz = max(a[rs(p)].hz, a[rs(p)].b + a[ls(p)].hz);
		a[p].zd = max(a[ls(p)].hz + a[rs(p)].qz, max(a[rs(p)].zd, a[ls(p)].zd));
	}
	void build(ll l, ll r, ll p) {
		if (l == r) {
			a[p].b = a[p].qz = a[p].hz = a[p].zd = c[l];
			return;
		}
		ll m = (l + r) >> 1;
		build(l, m, ls(p));
		build(m + 1, r, rs(p));
		pd(p);
	}
	void f(ll l, ll r, ll k, ll p) {

	}
	void pushd(ll l, ll r, ll p) {
		if (a[p].lazy != 0) {

		}
	}
	void update(ll x, ll l, ll r, ll p, ll k) {
		if (l == r) {
			a[p].b = a[p].qz = a[p].hz = a[p].zd = k;
			return;
		}
		ll m = (l + r) >> 1;
		if (x <= m) update(x, l, m, ls(p), k);
		if (x > m) update(x, m + 1, r, rs(p), k);
		pd(p);
	}
	tree sum(ll x, ll y, ll l, ll r, ll p) {
		tree i, j, k;
		i.init(), j.init(), k.init();
		if (x <= l && y >= r) {
			return a[p];
		}
		ll m = (l + r) >> 1;
		if (x <= m) i = sum(x, y, l, m, ls(p));
		if (y > m) j = sum(x, y, m + 1, r, rs(p));
		k.b = i.b + j.b;
		k.qz = max(i.qz, i.b + j.qz);
		k.hz = max(j.hz, j.b + i.hz);
		k.zd = max(i.hz + j.qz, max(i.zd, j.zd));
		return k;
	}
} tr;
ll n , m , l , r , k , op;
int main() {
	scanf("%lld%lld", &n, &m);
	for (int i = 1 ; i <= n ; i++) {
		scanf("%lld", &tr.c[i]);
	}
	tr.build(1 , n , 1);
	for (int i = 1 ; i <= m ; i++) {
		scanf("%lld%lld%lld", &op, &l, &r);
		if (op == 1) {
			if (l > r) {
				swap(l, r);
			}
			tree k = tr.sum(l, r, 1, n, 1);
			printf("%lld\n" , max(k.zd, max(k.qz, k.hz)));
		}
		else {
			tr.update(l, 1, n, 1, r);
		}
	}
}