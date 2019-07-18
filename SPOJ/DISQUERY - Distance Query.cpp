#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100100
#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
#define INF 0x7fffffff
template <typename Tp>
Tp max(Tp a, Tp b) {
	if (a > b) return a;
	else return b;
}
template <typename Tp>
Tp min(Tp a, Tp b) {
	if (a < b) return a;
	else return b;
}
struct Edge {
	int v, nx, w;
}e[MAXN << 2];
int head[MAXN], ecnt, m, son[MAXN], fa[MAXN], siz[MAXN], cnt;
int w[MAXN], wt[MAXN], top[MAXN], id[MAXN], dep[MAXN], n, x, y, z;
void add(int f, int t, int w) {
	e[++ecnt] = (Edge) {t, head[f], w};
	head[f] = ecnt;
}
struct Segtree {
	int a[MAXN], b[MAXN << 2], tmax[MAXN << 2], tmin[MAXN << 2];
	void pd(int p) {
		b[p] = b[ls(p)] + b[rs(p)];
		tmax[p] = max(tmax[ls(p)], tmax[rs(p)]);
		tmin[p] = min(tmin[ls(p)], tmin[rs(p)]);
	}
	void build(int p, int l, int r) {
		if (l == r) {
			b[p] = tmax[p] = tmin[p] = a[l];
			return;
		}
		int m = (l + r) >> 1;
		build(ls(p), l, m);
		build(rs(p), m + 1, r);
		pd(p);
	}
	int qmin(int x, int y, int l, int r, int p) {
		int ans = INF;
		if (x <= l && y >= r) {
			return tmin[p];
		}
		int m = (l + r) >> 1;
		if (x <= m) ans = min(qmin(x, y, l, m, ls(p)), ans);
		if (y > m) ans = min(qmin(x, y, m + 1, r, rs(p)), ans);
		return ans;
	}
	int qmax(int x, int y, int l, int r, int p) {
		int ans = -INF;
		if (x <= l && y >= r) {
			return tmax[p];
		}
		int m = (l + r) >> 1;
		if (x <= m) ans = max(qmax(x, y, l, m, ls(p)), ans);
		if (y > m) ans = max(qmax(x, y, m + 1, r, rs(p)), ans);
		return ans;
	}
} tree;
void dfs1(int u, int f, int d) {
	siz[u] = 1;
	fa[u] = f;
	dep[u] = d;
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (to == f) continue;
		dfs1(to, u, d + 1);
		w[to] = e[i].w;
		siz[u] += siz[to];
		if (siz[to] > siz[son[u]]) son[u] = to;
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
inline int qrmax(int x, int y) {
	int ans = -INF;
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) std::swap(x, y);
		ans = max(ans, tree.qmax(id[top[x]], id[x], 1, n, 1));
		x = fa[top[x]];
	}
	if (dep[x] > dep[y]) std::swap(x, y);
	ans = max(ans, tree.qmax(id[x] + 1, id[y], 1, n, 1));
	return ans;
}
inline int qrmin(int x, int y) {
	int ans = INF;
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) std::swap(x, y);
		ans = min(ans, tree.qmin(id[top[x]], id[x], 1, n, 1));
		x = fa[top[x]];
	}
	if (dep[x] > dep[y]) std::swap(x, y);
	ans = min(ans, tree.qmin(id[x] + 1, id[y], 1, n, 1));
	return ans;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d%d%d", &x, &y, &z);
		add(x, y, z);
		add(y, x, z);
	}
	dfs1(1, 0, 1);
	dfs2(1, 1);
	for (int i = 1; i <= n; i++) {
		tree.a[i] = wt[i];
	}
	tree.build(1, 1, n);
	scanf("%d", &m);
	while (m--) {
		scanf("%d%d", &x, &y);
		printf("%d %d\n", qrmin(x, y), qrmax(x, y));
	}
}