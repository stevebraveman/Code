#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1000100
#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
struct Edge {
	int v, nx;
}e[MAXN];
int head[MAXN], ecnt = 1, n, m, x, y, dep[MAXN], si[MAXN], wt[MAXN], w[MAXN], op;
int fa[MAXN], top[MAXN], son[MAXN], cnt, r = 1, id[MAXN], LCA;
void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
struct Segtree {
	int a[MAXN], b[MAXN << 2], tmax[MAXN << 2], c[MAXN << 2], d[MAXN << 2];
	void pd(int p) {
		b[p] = b[ls(p)] + b[rs(p)];
	}
	void updated(int x, int l, int r, int p, int k) {
		if (l == r) {
			b[p] = k;
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
inline void upd(int x, int k) {
	tree.updated(id[x], 1, n, 1, k);
}
inline int qrs(int x, int y) {
	int ans = 0;
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) std::swap(x, y);
		ans += tree.qsum(id[top[x]], id[x], 1, n, 1);
		x = fa[top[x]];
	}
	if (dep[x] > dep[y]) std::swap(x, y);
	LCA = x;
	ans += tree.qsum(id[x] + 1, id[y], 1, n, 1);
	return ans;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &x, &y);
		add(x, y);
		add(y, x);
	}
	scanf("%d", &m);
	dfs1(r, 0, 1);
	dfs2(r, r);
	while (m--) {
		scanf("%d", &op);
		if (op == 1) {
			scanf("%d", &x);
			int u = e[2 * x].v;
			int v = e[(2 * x) ^ 1].v;
			if (dep[u] > dep[v]) {
				upd(u, 0);
			}
			else {
				upd(v, 0);
			}
		}
		if (op == 2) {
			scanf("%d", &x);
			int u = e[2 * x].v;
			int v = e[(2 * x) ^ 1].v;
			if (dep[u] > dep[v]) {
				upd(u, 1);
			}
			else {
				upd(v, 1);
			}
		}
		if (op == 3) {
			scanf("%d%d", &x, &y);
			int tot = qrs(x, y);
			if (tot) {
				puts("-1");
			}
			else {
				printf("%d\n", dep[x] + dep[y] - 2 * dep[LCA]);
			}
		}
	}
}