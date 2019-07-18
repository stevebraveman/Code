#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100100
struct Edge {
	int v, nx;
} e[MAXN * 2];
int head[MAXN], ecnt, n, m, son[MAXN], dep[MAXN], top[MAXN], size[MAXN], r = 1, fa[MAXN], len;
int x, y;
void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
void dfs1(int u, int f, int d) {
	dep[u] = d;
	fa[u] = f;
	size[u] = 1;
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (to == f) continue;
		dfs1(to, u, d + 1);
		size[u] += size[to];
		if (size[son[u]] < size[to]) son[u] = to;
	}
}
void dfs2(int u, int topf) {
	top[u] = topf;
	if (!son[u]) return;
	dfs2(son[u], topf);
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (to == fa[u] || to == son[u]) continue;
		dfs2(to, to);
	}
}
int LCA(int x, int y) {
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) std::swap(x, y);
		x = fa[top[x]];
	}
	if (dep[x] > dep[y]) std::swap(x, y);
	return x;
}
int tot, ls[MAXN], a[MAXN], b[MAXN << 2], ls[MAXN << 2], rs[MAXN << 2];
void build(int &p, int l, int r) {
	p = ++tot;
	if (l == r) {
		return;
	}
	int m = (l + r) >> 1;
	build(ls[p], l, m);
	build(rs[p], m + 1, r);
}
int insert(int x, int l, int r, int p) {
	int _p = ++tot;
	ls[_p] = ls[p];
	rs[_p] = rs[p];
	b[_p] = b[p] + 1;
	if (l == r) {
		return _p;
	}
	int m = (l + r) >> 1;
	if (x <= m) ls[_p] = insert(x, l, m, ls[p]);
	else rs[_p] = insert(x, m + 1, r, rs[p]);
	return _p;
}
int ask(int x, int y, int l, int r, int k) {
	int ans, x = b[ls[y]] - b[ls[x]];
	if (l == r) {
		return l;
	}
	int m = (l + r) >> 1;
	if (x <= m) ans = ask(ls[x], ls[y], l, m, k);
	else ans = ask(rs[x], rs[y], m + 1, r, k - x);
	return ans;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		ls[i] = a[i];
	}
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &x, &y);
		add(x, y);
		add(y, x);
	}
	dfs1(1)
	std::sort(ls + 1, ls + 1 + n);
	len = std::unique(ls + 1, ls + 1 + n) - ls - 1;
	build(b[0], 1, len);
	for (int i = 1; i <= n; i++) {
		int x = std::lower_bound(ls + 1, ls + 1 + len, a[i]) - a;
		b[i] = insert(x, 1, len, b[i - 1]);
	}
	while (m--) {
		scanf("%d%d", )
	}
}