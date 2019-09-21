#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
#define INF 0x7fffffff
#define MAXN 3001000
int max(int a, int b) {
	if (a > b) return a;
	else return b;
}
void swap(int &x, int &y) {
	int t = x;
	x = y;
	y = t;
}
struct Edge {
	int v, nx;
}e[MAXN];
int head[MAXN], ecnt, n, m, x, y, dep[MAXN], si[MAXN], wt[MAXN], w[MAXN];
int fa[MAXN], top[MAXN], son[MAXN], cnt, r = 1, id[MAXN], sx[MAXN];
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
	void f(int p, int l, int r, int k) {
		lazy[p] += k;
		b[p] += k * (r - l + 1);
		return;
	}
	void pushd(int p, int l, int r) {
		if (lazy[p]) {
			int m = (l + r) >> 1;
			f(ls(p), l, m, lazy[p]);
			f(rs(p), m + 1, r, lazy[p]);
			lazy[p] = 0;
			return;
		}
	}
	void updater(int x, int y, int l, int r, int p, int k) {
		if (x <= l && y >= r) {
			lazy[p] += k;
			b[p] += k * (r - l + 1);
			return;
		}
		pushd(p, l, r);
		int m = (l + r) >> 1;
		if (x <= m) updater(x, y, l, m, ls(p), k);
		if (y > m) updater(x, y, m + 1, r, rs(p), k);
		pd(p);
	}
	int qd(int x, int l, int r, int p) {
		if (l == r) {
			return b[p];
		}
		int m = (l + r) >> 1;
		pushd(p, l, r);
		if (x <= m) return qd(x, l, m, ls(p));
		else return qd(x, m + 1, r, rs(p));
	}
}tree;
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
inline void uprs(int x, int y, int k) {
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		tree.updater(id[top[x]], id[x], 1, n, 1, k);
		x = fa[top[x]];
	}
	if (dep[x] > dep[y]) swap(x, y);
	tree.updater(id[x], id[y], 1, n, 1, k);
}
inline int qde(int x) {
	return tree.qd(id[x], 1, n, 1);
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &sx[i]);
	}
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &x, &y);
		add(x, y);
		add(y, x);
	}
	dfs1(r, -1, 1);
	dfs2(r, r);
	tree.build(1, n, 1);
	for (int i = 1; i < n; i++) {
		uprs(sx[i], sx[i + 1], 1);
		uprs(sx[i + 1], sx[i + 1], -1);
	}
	for (int i = 1; i <= n; i++) {
		printf("%d\n", qde(i));
	}
}