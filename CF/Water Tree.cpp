#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
#define INF 0x7fffffff
#define MAXN 500100
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
}e[MAXN << 2];
int head[MAXN], ecnt, n, m, x, y, dep[MAXN], si[MAXN], wt[MAXN], w[MAXN];
int fa[MAXN], top[MAXN], son[MAXN], cnt, r = 1, id[MAXN];
void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
struct Segtree {
	int b[MAXN << 2], lazy[MAXN << 2];
	void pd(int p) {
		b[p] = b[ls(p)] + b[rs(p)];
	}
	void build(int l, int r, int p) {
		lazy[p] = -1;
		if (l == r) {
			b[p] = 0;
			return;
		}
		int m = (l + r) >> 1;
		build(l, m, ls(p));
		build(m + 1, r, rs(p));
		pd(p);
	}
	void f(int l, int r, int p, int k) {
		lazy[p] = k;
		b[p] = (r - l + 1) * k;
	}
	void pushd(int l, int r, int p) {
		if (lazy[p] != -1) {
			int m = (l + r) >> 1;
			f(l, m, ls(p), lazy[p]);
			f(m + 1, r, rs(p), lazy[p]);
			lazy[p] = -1;
		}
	}
	void updated(int x, int y, int l, int r, int p, int k) {
		if (x <= l && y >= r) {
			lazy[p] = k;
			b[p] = (r - l + 1) * k;
			return;
		}
		int m = (l + r) >> 1;
		pushd(l, r, p);
		if (x <= m) updated(x, y, l, m, ls(p), k);
		if (y > m) updated(x, y, m + 1, r, rs(p), k);
		pd(p);
	}
	int ask(int x, int l, int r, int p) {
		if (l == r) {
			return b[p];
		}
		pushd(l, r, p);
		int m = (l + r) >> 1;
		if (x <= m) return ask(x, l, m, ls(p));
		else return ask(x, m + 1, r, rs(p));
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
	top[u] = topf;
	if (!son[u]) return;
	dfs2(son[u], topf);
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (fa[u] == to || to == son[u]) continue;
		dfs2(to, to);
	}
}
inline void qrs(int x, int y) {
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		tree.updated(id[top[x]], id[x], 1, n, 1, 0);
		x = fa[top[x]];
	}
	if (dep[x] > dep[y]) swap(x, y);
	tree.updated(id[x], id[y], 1, n, 1, 0);
}
inline void upd(int x) {
	tree.updated(id[x], id[x] + si[x] - 1, 1, n, 1, 1);
	return;
}
inline int askp(int x) {
	return tree.ask(id[x], 1, n, 1);
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &x, &y);
		add(x, y);
		add(y, x);
	}
	dfs1(r, -1, 1);
	dfs2(r, r);
	scanf("%d", &m);
	tree.build(1, n, 1);
	while (m--) {
		int op;
		scanf("%d%d", &op, &x);
		if (op == 1) {
			upd(x);
		}
		if (op == 2) {
			qrs(x, 1);
		}
		if (op == 3) {
			printf("%d\n", askp(x));
		}
	}
}