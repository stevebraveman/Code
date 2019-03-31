#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
#define INF 0x7fffffff
#define MAXN 100100
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
int fa[MAXN], top[MAXN], son[MAXN], cnt, r = 1, id[MAXN];
void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
struct Segtree {
	int a[MAXN], b[MAXN << 2], tmax[MAXN << 2];
	void pd(int p) {
		b[p] = b[ls(p)] + b[rs(p)];
		tmax[p] = max(tmax[ls(p)], tmax[rs(p)]);
	}
	void build(int l, int r, int p) {
		if (l == r) {
			b[p] = tmax[p] = a[l];
			return;
		}
		int m = (l + r) >> 1;
		build(l, m, ls(p));
		build(m + 1, r, rs(p));
		pd(p);
	}
	void updated(int x, int l, int r, int p, int k) {
		if (l == r) {
			b[p] = tmax[p] = k;
			return;
		}
		int m = (l + r) >> 1;
		if (x <= m) updated(x, l, m, ls(p), k);
		else updated(x, m + 1, r, rs(p), k);
		pd(p);
	}
	int qmax(int x, int y, int l, int r, int p) {
		int s = -INF;
		if (x <= l && y >= r) {
			return tmax[p];
		}
		int m = (l + r) >> 1;
		if (x <= m) s = max(qmax(x, y, l, m, ls(p)), s);
		if (y > m) s = max(qmax(x, y, m + 1, r, rs(p)), s);
		return s;
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
inline int qrs(int x, int y) {
	int ans = 0;
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		ans += tree.qsum(id[top[x]], id[x], 1, n, 1);
		x = fa[top[x]];
	}
	if (dep[x] > dep[y]) swap(x, y);
	ans += tree.qsum(id[x], id[y], 1, n, 1);
	return ans;
}
inline int qrm(int x, int y) {
	int ans = -INF;
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		ans = max(tree.qmax(id[top[x]], id[x], 1, n, 1), ans);
		x = fa[top[x]];
	}
	if (dep[x] > dep[y]) swap(x, y);
	ans = max(tree.qmax(id[x], id[y], 1, n, 1), ans);
	return ans;
}
inline void upd(int x, int k) {
	tree.updated(id[x], 1, n, 1, k);
	return;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &x, &y);
		add(x, y);
		add(y, x);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
	}
	dfs1(r, -1, 1);
	dfs2(r, r);
	for (int i = 1; i <= n; i++) {
		tree.a[i] = wt[i];
	}
	tree.build(1, n, 1);
	scanf("%d", &m);
	while (m--) {
		char op[10];
		scanf("%s", op);
		if (op[1] == 'M') {
			scanf("%d%d", &x, &y);
			printf("%d\n", qrm(x, y));
		}
		if (op[1] == 'H') {
			scanf("%d%d", &x, &y);
			upd(x, y);
		}
		if (op[1] == 'S') {
			scanf("%d%d", &x, &y);
			printf("%d\n", qrs(x, y));
		}
	}
}