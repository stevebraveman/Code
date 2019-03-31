#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
#define MAXN 1000010
#define ll long long
#define INF 0x7fffffff
ll min(ll a, ll b) {
	if (a < b) return a;
	else return b;
}
ll max(ll a, ll b) {
	if (a > b) return a;
	else return b;
}
ll f[MAXN], p[MAXN], ans = 0x7ffffffffffLL, n,m ;
struct Segtree {
	ll a[MAXN], b[MAXN << 2];
	void pd(ll p) {
		b[p] = max(b[ls(p)], b[rs(p)]);
	}
	void build(ll p, ll l, ll r) {
		if (l == r) {
			b[p] = a[l];
			return;
		}
		ll m = (l + r) >> 1;
		build(ls(p), l, m);
		build(rs(p), m + 1, r);
		pd(p);
	}
	ll ask(ll x, ll y, ll l, ll r, ll p) {
		ll ans = -INF;
		if (x <= l && y >= r) {
			return b[p];
		}
		ll m = (l + r) >> 1;
		if (x <= m) ans = max(ask(x, y, l, m, ls(p)), ans);
		if (y > m) ans = max(ask(x, y, m + 1, r, rs(p)), ans);
		return ans;
	}
}tr;
int main() {
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld%lld", &f[i], &tr.a[i]);
		p[i] = p[i - 1] + f[i];
	}
	tr.build(1, 1, n);
	for (int i = 1; i <= n; i++) {
		ll pos = std::lower_bound(p + i, p + 1 + n, p[i - 1] + m) - p;
		if (pos <= n) ans = min(ans, tr.ask(i, pos, 1, n, 1));
	}
	printf("%lld", ans);
	return 0;
}