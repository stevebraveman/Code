#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAXN 100010
struct Edge {
	int v, nx;
}e[MAXN << 2];
int head[MAXN], ecnt, n, m, x[MAXN], y[MAXN], dep[MAXN], si[MAXN], wt[MAXN], w[MAXN];
int fa[MAXN], top[MAXN], son[MAXN], cnt, r = 1, id[MAXN], op[MAXN], qx[MAXN], qy[MAXN];
void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
struct Segtree {
	int a[MAXN], b[MAXN << 2], lazy[MAXN << 2];
	void pd(int p) {
		b[p] = b[ls(p)] + b[rs(p)];
	}
	void build(int l, int r, int p) {
		lazy[p] = 0;
		if (l == r) {
			b[p] = a[l];
			return;
		}
		int m = (l + r) >> 1;
		build(l, m, ls(p));
		build(m + 1, r, rs(p));
		pd(p);
	}
	void f(int l, int r, int k, int p) {
		b[p] = k;
		lazy[p] = k;
	}
	void pushd(int l, int r, int p) {
		if (lazy[p]) {
			int m = (l + r) >> 1;
			f(l, m, lazy[p], ls(p));
			f(m, r + 1, lazy[p], rs(p));
			lazy[p] = 0;
		}
	}
	void updated(int x, int y, int l, int r, int p, int k) {
		if (x <= l && y >= r) {
			b[p] = k;
			lazy[p] = k;
			return;
		}
		pushd(l, r, p);
		int m = (l + r) >> 1;
		if (x <= m) updated(x, y, l, m, ls(p), k);
		else updated(x, y, m + 1, r, rs(p), k);
		pd(p);
	}
	int qsum(int x, int y, int l, int r, int p) {
		int s = 0;
		if (x <= l && y >= r) {
			return b[p];
		}
		int m = (l + r) >> 1;
		if (x <= m) s += qsum(x, y, l, m, ls(p));
		if (y > m) s += qsum(x, y, m + 1, r, rs(p));
		return s;
	}
}tree;
void tarjan(int u, int f) {
	dfn[u] = low[u] = ++tim;
	st[++tp] = u;
}
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
inline void change(int x, int y) {
	int ans = -INF;
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		tree.updated(id[top[x]], id[x], 1, n, 1, 1);
		x = fa[top[x]];
	}
	if (dep[x] > dep[y]) swap(x, y);
	tree.updated(id[x] + 1, id[y], 1, n, 1, 1);
}
inline int qrm(int x, int y) {
	int ans = 0;
	int u = x, v = y;
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		ans += tree.qsum(id[top[x]], id[x], 1, n, 1, 1);
		x = fa[top[x]];
	}
	if (dep[x] > dep[y]) swap(x, y);
	ans += tree.qsum(id[x] + 1, id[y], 1, n, 1, 1);
	int LCA = dep[u] + dep[v] - 2 * dep[x];
	return LCA - ans;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &x[i], &y[i]);
	}
	dfs1(r, 0, 1);
	dfs2(r, r);
	tree.build(1, n, 1);
	while (m--) {
		scanf("%d%d", )
	}
}