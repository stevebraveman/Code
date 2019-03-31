#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
#define MAXN 5000100
#define INF 19260817
#define ll long long
ll max(ll a, ll b) {
	if (a > b) return a;
	else return b;
}
struct Segtree {
	ll a[MAXN], tmax[MAXN << 2], lazy[MAXN << 2]
	bool fyw[MAXN << 2];
	void pd(ll p) {
		tmax[p] = max(tmax[rs(p)], tmax[ls(p)]);
		fyw[p] = fyw[ls(p)] | fyw[rs(p)];
	}
	void build(ll p, ll l, ll r) {
		if (l == r) {
			tmax[p] = a[l];
			return;
		}
		ll m = (l + r) >> 1;
		build(ls(p), l, m);
		build(rs(p), m + 1, r);
		pd(p);
	}
	void f(ll p, ll l, ll r, ll k) {
		lazy[p] += k;
		tmax[p] += k;
	}
	void pushd(ll p, ll l, ll r) {
		if (lazy[p]) {
			ll m = (l + r) >> 1;
			f(ls(p), l, m, lazy[p]);
			f(rs(p), m + 1, r, lazy[p]);
			lazy[p] = 0;
			return;
		}
	}
	void updated(ll x, ll l, ll r, ll p, ll k) {
		if (l == r) {
			tmax[p] = k - tmax[p];
			return;
		}
		pushd(p, l, r);
		ll m = (l + r) >> 1;
		if (x <= m) updated(x, l, m, ls(p), k);
		else updated(x, m + 1, r, rs(p), k);
		pd(p);
	}
	void updater(ll x, ll y, ll l, ll r, ll p, ll k) {
		if (x <= l && y >= r) {
			lazy[p] += k;
			tmax[p] += k;
			return;
		}
		pushd(p, l, r);
		ll m = (l + r) >> 1;
		if (x <= m) updater(x, y, l, m, ls(p), k);
		if (y > m) updater(x, y, m + 1, r, rs(p), k);
		pd(p);
	}
	bool fyw(ll x, ll y, ll l, ll r, ll p, ll k) {
		if (x <= l && y >= r) {
			
		}
	}
	ll query(ll x, ll y, ll l, ll r, ll p) {
		ll ans = -INF;
		if (x <= l && y >= r) {
			ll k = tmax[p];
			tmax[p] = 0;
			return k;
		}
		pushd(p, l, r);
		ll m = (l + r) >> 1;
		if (x <= m) ans = max(query(x, y, l, m, ls(p)), ans);
		if (y > m) ans = max(query(x, y, m + 1, r, rs(p)), ans);
		return ans;
	}
} tree;
ll n, m, l, r, op, k;
int main() {
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &tree.a[i]);
	}
	tree.build(1, 1, n);
	while (m--) {
		scanf("%lld", &op);
		switch(op) {
			case 1: {
				scanf("%lld%lld", &l, &k);
				tree.updated(l, 1, n, 1, k);
			}
			case 2: {
				scanf("%lld%lld", &l, &r);
				prllf("%lld\n", tree.query(l, r, 1, n, 1));
			}
		}
	}
}