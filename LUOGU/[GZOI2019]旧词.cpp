#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100100
#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
struct Edge {
	int v, nx;
}e[MAXN << 1];
int head[MAXN], fa[MAXN], ecnt, n, m, x, y, dep[MAXN], son[MAXN], siz[MAXN], id[MAXN], cnt;
int lazy[MAXN], b[MAXN];
void pd(int p) {
	b[p] = b[ls(p)] + b[rs(p)];
}
void f(int l, int r, int k, int p) {
	lazy[p] += k;
	b[p] += (r - l + 1) * k;
}
void pushd(int l, int r, int p) {
	if (lazy[p]) {
		int m = (l + r) >> 1;
		f(l, m, lazy[p], ls(p));
		f(m + 1, r, lazy[p], rs(p));
		lazy[p] = 0;
	}
}
void chg(int x, int y, int l, int r, int k, int p) {
	if (x <= l && y >= r) {
		f(l, r, k, p);
		return;
	}
	int m = (l + r) >> 1;
	pushd(l, r, p);
	if (x <= m) chg(x, y, l, m, k, ls(p));
	if (y > m) chg(x, y, m + 1, r, k, rs(p));
	pd(p);
}
int 
void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
void dfs(int u, int f, int d) {
	dep[u] = d;
	siz[u] = 1;
	fa[u] = f;
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (to == f) continue;
		dfs(to, u, d + 1);
		siz[u] += siz[to];
		if (siz[son[u]] < son[to]) son[u] = to;
	}
}
void dfs2(int u, int topf) {
	id[u] = ++cnt;
	if (!son[u]) return;
	dfs2(to, topf);
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (to == fa[u] || to == son[u]) continue;
		dfs2(to, to);
	}
}
void modi(int x, int y, int k) {
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) std::swap(x, y);

		x = fa[top[x]];
	}
}