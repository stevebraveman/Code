#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
#define INF 0x7fffffff
#define MAXN 1001000
#define ll long long
ll max(ll a, ll b) {
	if (a > b) return a;
	else return b;
}
void swap(ll &x, ll &y) {
	ll t = x;
	x = y;
	y = t;
}
struct Edge {
	ll v, nx;
}e[MAXN];
ll head[MAXN], ecnt, n, m, x, y, dep[MAXN], si[MAXN], wt[MAXN], w[MAXN];
ll fa[MAXN], top[MAXN], son[MAXN], cnt, r = 1, id[MAXN];
void add(ll f, ll t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
struct Segtree {
	ll a[MAXN], b[MAXN << 2], lazy[MAXN << 2];
	void pd(ll p) {
		b[p] = b[ls(p)] + b[rs(p)];
	}
	void build(ll l, ll r, ll p) {
		lazy[p] = 0;
		if (l == r) {
			b[p] = a[l];
			return;
		}
		ll m = (l + r) >> 1;
		build(l, m, ls(p));
		build(m + 1, r, rs(p));
		pd(p);
	}
	void f(ll p, ll l, ll r, ll k) {
		lazy[p] += k;
		b[p] += k * (r - l + 1);
		return;
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
	void updater(ll x, ll y, ll l, ll r, ll p, ll k) {
		if (x <= l && y >= r) {
			lazy[p] += k;
			b[p] += k * (r - l + 1);
			return;
		}
		pushd(p, l, r);
		ll m = (l + r) >> 1;
		if (x <= m) updater(x, y, l, m, ls(p), k);
		if (y > m) updater(x, y, m + 1, r, rs(p), k);
		pd(p);
	}
	void updated(ll x, ll l, ll r, ll p, ll k) {
		if (l == r) {
			b[p] += k;
			return;
		}
		ll m = (l + r) >> 1;
		pushd(p, l, r);
		if (x <= m) updated(x, l, m, ls(p), k);
		else updated(x, m + 1, r, rs(p), k);
		pd(p);
	}
	ll qsum(ll x, ll y, ll l, ll r, ll p) {
		ll s = 0;
		if (x <= l && y >= r) {
			return b[p];
		}
		pushd(p, l, r);
		ll m = (l + r) >> 1;
		if (x <= m) s += qsum(x, y, l, m, ls(p));
		if (y > m) s += qsum(x, y, m + 1, r, rs(p));
		return s;
	}
}tree;
void dfs1(ll u, ll f, ll deep) {
	dep[u] = deep;
	fa[u] = f;
	si[u] = 1;
	for (ll i = head[u]; i; i = e[i].nx) {
		ll to = e[i].v;
		if (to == f) continue;
		dfs1(to, u, deep + 1);
		si[u] += si[to];
		if (si[to] > si[son[u]]) son[u] = to;
	}
}
void dfs2(ll u, ll topf) {
	id[u] = ++cnt;
	wt[cnt] = w[u];
	top[u] = topf;
	if (!son[u]) return;
	dfs2(son[u], topf);
	for (ll i = head[u]; i; i = e[i].nx) {
		ll to = e[i].v;
		if (fa[u] == to || to == son[u]) continue;
		dfs2(to, to);
	}
}
ll qrs(ll x, ll y) {
	ll ans = 0;
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		ans += tree.qsum(id[top[x]], id[x], 1, n, 1);
		x = fa[top[x]];
	}
	if (dep[x] > dep[y]) swap(x, y);
	ans += tree.qsum(id[x], id[y], 1, n, 1);
	return ans;
}
void ups(ll x, ll k) {
	tree.updater(id[x], id[x] + si[x] - 1, 1, n, 1, k);
}
void upd(ll x, ll k) {
	tree.updated(id[x], 1, n, 1, k);
	return;
}
int main() {
	scanf("%lld%lld", &n, &m);
	for (ll i = 1; i <= n; i++) {
		scanf("%lld", &w[i]);
	}
	for (ll i = 1; i < n; i++) {
		scanf("%lld%lld", &x, &y);
		add(x, y);
		add(y, x);
	}
	dfs1(r, -1, 1);
	dfs2(r, r);
	for (ll i = 1; i <= n; i++) {
		tree.a[i] = wt[i];
	}
	tree.build(1, n, 1);
	while (m--) {
		ll op;
		scanf("%lld", &op);
		switch(op) {
			case 1: {
				scanf("%lld%lld", &x, &y);
				upd(x, y);
				break;
			}
			case 2: {
				scanf("%lld%lld", &x, &y);
				ups(x, y);
				break;
			}
			case 3: {
				scanf("%lld", &x);
				printf("%lld\n", qrs(1, x));
				break;
			}
		}
	}
}