#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
struct Edge {
	int v, nx;
}e[MAXN << 2];
int head[MAXN], ecnt, n, m, x, y, dep[MAXN], son[MAXN], siz[MAXN], fa[MAXN], r = 1, id[MAXN], wt[MAXN], w[MAXN], top[MAXN];
int cnt, op;
void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
struct Segtree {
	int a[MAXN], b[MAXN << 2];
	void pd(int p) {
		b[p] = b[ls(p)] ^ b[rs(p)];
	}
	void build(int p, int l, int r) {
		if (l == r) {
			b[p] = a[l];
			return;
		}
		int m = (l + r) >> 1;
		build(ls(p), l, m);
		build(rs(p), m + 1, r);
		pd(p);
	}
	void update(int x, int l, int r, int p, int k) {
		if (l == r) {
			b[p] = k;
			return;
		}
		int m = (l + r) >> 1;
		if (x <= m) update(x, l, m, ls(p), k);
		else update(x, m + 1, r, rs(p), k);
		pd(p);
	}
	int ask(int x, int y, int l, int r, int p) {
		int ans = 0;
		if (x <= l && y >= r) {
			return b[p];
		}
		int m = (l + r) >> 1;
		if (x <= m) ans ^= ask(x, y, l, m, ls(p));
		if (y > m) ans ^= ask(x, y, m + 1, r, rs(p));
		return ans;
	}
}tr;
void dfs1(int u, int f, int deep) {
	dep[u] = deep;
	fa[u] = f;
	siz[u] = 1;
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (to == f) continue;
		dfs1(to, u, deep + 1);
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
inline void upd(int x, int k) {
	tr.update(id[x], 1, n, 1, k);
}
int qrs(int x, int y) {
	int ans = 0;
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) std::swap(x, y);
		ans ^= tr.ask(id[top[x]], id[x], 1, n, 1);
		x = fa[top[x]];
	}
	if (dep[x] > dep[y]) std::swap(x, y);
	ans ^= tr.ask(id[x], id[y], 1, n, 1);
	return ans;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &w[i]);
	}
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &x, &y);
		add(x, y);
		add(y, x);
	}
	dfs1(r, 0, 1);
	dfs2(r, r);
	for (int i = 1; i <= n; i++) {
		tr.a[i] = wt[i];
	}
	tr.build(1, 1, n);
	while (m--) {
		scanf("%d%d%d", &op, &x, &y);
		if (op == 1) {
			upd(x, y);
		}
		else {
			printf("%d\n", qrs(x, y));
		}
	}
}