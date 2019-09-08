#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
#define INF 0x7fffffff
struct Edge {
	int v, nx;
}e[MAXN << 2];
template <typename Tp>
void swap(Tp &a, Tp &b) {
	Tp t = a;
	a = b;
	b = t;
}
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
int head[MAXN], ecnt, n, m, x, y, dep[MAXN], si[MAXN], wt[MAXN], w[MAXN];
int fa[MAXN], top[MAXN], son[MAXN], cnt, r = 1, id[MAXN], nid[MAXN];
void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
struct Segtree {
	int a[MAXN], tmin[MAXN << 2];
	void pd(int p) {
		tmin[p] = min(tmin[ls(p)], tmin[rs(p)]);
	}
	void build(int l, int r, int p) {
		if (l == r) {
			tmin[p] = INF;
			return;
		}
		int m = (l + r) >> 1;
		build(l, m, ls(p));
		build(m + 1, r, rs(p));
		pd(p);
	}
	void updated(int x, int l, int r, int p, int k) {
		if (l == r) {
			tmin[p] = k;
			return;
		}
		int m = (l + r) >> 1;
		if (x <= m) updated(x, l, m, ls(p), k);
		else updated(x, m + 1, r, rs(p), k);
		pd(p);
	}
	int qmin(int x, int y, int l, int r, int p) {
		int s = INF;
		if (x <= l && y >= r) {
			return tmin[p];
		}
		int m = (l + r) >> 1;
		if (x <= m) s = min(qmin(x, y, l, m, ls(p)), s);
		if (y > m) s = min(qmin(x, y, m + 1, r, rs(p)), s);
		return s;
	}
	bool ask(int x, int l, int r, int p) {
		if (l == r) {
			return (tmin[p] == INF);
		}
		int m = (l + r) >> 1;
		if (x <= m) return ask(x, l, m, ls(p));
		else return ask(x, m + 1, r, rs(p));
	}
}tr;
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
	nid[cnt] = u;
	top[u] = topf;
	if (!son[u]) return;
	dfs2(son[u], topf);
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (fa[u] == to || to == son[u]) continue;
		dfs2(to, to);
	}
}
inline int qrs(int x, int y) {
	int ans = INF;
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		ans = min(ans, tr.qmin(id[top[x]], id[x], 1, n, 1));
		x = fa[top[x]];
	}
	if (dep[x] > dep[y]) swap(x, y);
	ans = min(tr.qmin(id[x], id[y], 1, n, 1), ans);
	if (ans == INF) return -1;
	else return nid[ans];
}
inline void update(int x) {
	bool ans = tr.ask(id[x], 1, n, 1);
	if (ans) {
		tr.updated(id[x], 1, n, 1, id[x]);
	}
	else {
		tr.updated(id[x], 1, n, 1, INF);
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &x, &y);
		add(x, y);
		add(y, x);
	}
	dfs1(r, 0, 1);
	dfs2(r, r);
	tr.build(1, n, 1);
	// for (int i = 1; i <= n; i++) {
	// 	printf("%d ", id[i]);
	// }
	// puts("");
	while (m--) {
		scanf("%d%d", &x, &y);
		if (!x) {
			update(y);
		}
		else {
			printf("%d\n", qrs(1, y));
		}
	}
	return 0;
}