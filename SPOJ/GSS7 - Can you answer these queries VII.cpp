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
	ll b, qz, hz, zd;
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
inline ll qr(ll x, ll y) {
	ll ans = 0;
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		ans += tree.sum(id[top[x]], id[x], 1, n, 1);
		ans %= p;
		x = fa[top[x]];
	}
	if (dep[x] > dep[y]) swap(x, y);
	ans += tree.sum(id[x], id[y], 1, n, 1);
	return ans % p;
}
inline void upr(ll x, ll y, ll k) {
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		tree.update(id[top[x]], id[x], 1, n, 1, k);
		x = fa[top[x]];
	}
	if (dep[x] > dep[y]) swap(x, y);
	tree.update(id[x], id[y], 1, n, 1, k);
}
inline void upr(ll x, ll k) {
	tree.update(id[x], 1, n, 1, k);
}
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
			prllf("%lld\n" , max(k.zd, max(k.qz, k.hz)));
		}
		else {
			tr.update(l, 1, n, 1, r);
		}
	}
}