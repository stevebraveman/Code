#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 600010
#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
struct Edge {
	int v, nx;
}e[MAXN];
int head[MAXN], ecnt, n, m, x[MAXN], y[MAXN], dep[MAXN], si[MAXN], wt[MAXN], w[MAXN], _x, _y;
int fa[MAXN], top[MAXN], son[MAXN], cnt, r = 1, id[MAXN], ccnt;
char op;
void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
struct Segtree {
	int a[MAXN], b[MAXN << 2], tmax[MAXN << 2];
	void pd(int p) {
		b[p] = b[ls(p)] + b[rs(p)];
	}
	void build(int l, int r, int p) {
		if (l == r) {
			b[p] = a[l];
			return;
		}
		int m = (l + r) >> 1;
		build(l, m, ls(p));
		build(m + 1, r, rs(p));
		pd(p);
	}
	void updated(int x, int l, int r, int p, int k) {
		if (l == r) {
			b[p] += k;
			return;
		}
		int m = (l + r) >> 1;
		if (x <= m) updated(x, l, m, ls(p), k);
		else updated(x, m + 1, r, rs(p), k);
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
inline int qrs(int x, int y) {
	int ans = 0;
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) std::swap(x, y);
		ans += tree.qsum(id[top[x]], id[x], 1, n, 1);
		x = fa[top[x]];
	}
	if (dep[x] > dep[y]) std::swap(x, y);
	ans += tree.qsum(id[x] + 1, id[y], 1, n, 1);
	return ans;
}
inline void change(int x, int k) {
	tree.updated(id[x], 1, n, 1, k);
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &_x, &_y);
		add(_x, _y);
		add(_y, _x);
	}
	dfs1(r, -1, 1);
	dfs2(r, r);
	while (m--) {
		std::cin >> op;
		if (op == 'C') {
			ccnt++;
			scanf("%d%d", &x[ccnt], &y[ccnt]);
			if (dep[x[ccnt]] < dep[y[ccnt]]) std::swap(x[ccnt], y[ccnt]);
			change(x[ccnt], 1);
		}
		if (op == 'Q') {
			scanf("%d%d", &_x, &_y);
			if (qrs(_x, _y)) {
				puts("No");
			}
			else {
				puts("Yes");
			}
		}
		if (op == 'U') {
			scanf("%d", &_x);
			change(x[_x], -1);
		}
	}
}