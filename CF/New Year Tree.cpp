#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
#define MAXN 1001000
#define int long long
void swap(int &x, int &y) {
	int t = x;
	x = y;
	y = t;
}
struct Edge {
	int v, nx;
}e[MAXN];
int head[MAXN], ecnt, n, m, x, y, dep[MAXN], si[MAXN], wt[MAXN], w[MAXN];
int fa[MAXN], top[MAXN], son[MAXN], cnt, r = 1, id[MAXN], a[MAXN], op, ans, tot;
void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
struct Segtree {
	int b[MAXN << 2], lazy[MAXN << 2], a[MAXN];
	void pd(int p) {
		b[p] = b[ls(p)] | b[rs(p)];
	}
	void build(int p, int l, int r) {
		lazy[p] = 0;
		if (l == r) {
			b[p] = a[l];
			return;
		}
		int m = (l + r) >> 1;
		build(ls(p), l, m);
		build(rs(p), m + 1, r);
		pd(p);
	}
	void f(int p, int l, int r, int k) {
		lazy[p] = k;
		b[p] = k;
	}
	void pushd(int p, int l, int r) {
		if (lazy[p]) {
			int m = (l + r) >> 1;
			f(ls(p), l, m, lazy[p]);
			f(rs(p), m + 1, r, lazy[p]);
			lazy[p] = 0;
		}
	}
	void update(int x, int y, int l, int r, int p, int k) {
		if (x <= l && y >= r) {
			b[p] = k;
			lazy[p] = k;
			return;
		}
		pushd(p, l, r);
		int m = (l + r) >> 1;
		if (x <= m) update(x, y, l, m, ls(p), k);
		if (y > m) update(x, y, m + 1, r, rs(p), k);
		pd(p);
	}
	int qor(int x, int y, int l, int r, int p) {
		int s = 0;
		if (x <= l && y >= r) {
			return b[p];
		}
		pushd(p, l, r);
		int m = (l + r) >> 1;
		if (x <= m) s |= qor(x, y, l, m, ls(p));
		if (y > m) s |= qor(x, y, m + 1, r, rs(p));
		return s;
	}
} tree;
void dfs1(int u, int f, int deep) {
	dep[u] = deep;
	fa[u] = f;
	si[u] = 1;
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (to == f) continue;
		dfs1(to, u, deep + 1);
		si[u] += si[to];
		if (si[to] > si[son[u]]) son[u] = to;
	}
}
void dfs2(int u, int topf) {
	id[u] = ++cnt;
	wt[cnt] = w[u];
	top[u] = topf;
	if (!son[u]) return;
	dfs2(son[u], topf);
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (fa[u] == to || to == son[u]) continue;
		dfs2(to, to);
	}
}
inline int qs(int x) {
	return tree.qor(id[x], id[x] + si[x] - 1, 1, n, 1);
}
inline void ups(int x, int k) {
	tree.update(id[x], id[x] + si[x] - 1, 1, n, 1, k);
}
signed main() {
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
		w[i] = (1LL << (w[i] - 1));
	}
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &x, &y);
		add(x, y);
		add(y, x);
	}
	dfs1(r, -1, 1);
	dfs2(r, r);
	for (int i = 1; i <= n; i++) {
		tree.a[i] = wt[i];
	}
	tree.build(1, 1, n);
	while (m--) {
		scanf("%lld", &op);
		if (op == 1) {
			scanf("%lld%lld", &x, &y);
			y = 1LL << (y - 1);
			ups(x, y);
		}
		else {
			scanf("%lld", &x);
			tot = 0;
			ans = qs(x);
			for (int i = 0; i < 60; i++) {
				if (ans & (1LL << i)) tot++; 
			}
			printf("%lld\n", tot);
		}
	}
}