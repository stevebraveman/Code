#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#define MAXN 150000
#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
struct Edge {
	int v, nx;
} e[MAXN << 2];
int head[MAXN], ecnt, n, m, x, y, dep[MAXN], son[MAXN], fa[MAXN], top[MAXN], si[MAXN], id[MAXN], cnt, r = 1;
void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
struct Segtree {
	int b[MAXN << 2];
	void pd(int p) {
		b[p] = b[ls(p)] + b[rs(p)];
	}
	void upd(int x, int l, int r, int p) {
		if (l == r) {
			b[p] = 1;
			return;
		}
		int m = (l + r) >> 1;
		if (x <= m) upd(x, l, m, ls(p));
		else upd(x, m + 1, r, rs(p));
		pd(p);
	}
	int ask(int x, int y, int l, int r, int p) {
		int s = 0;
		if (x <= l && y >= r) {
			return b[p];
		}
		int m = (l + r) >> 1;
		if (x <= m) s += ask(x, y, l, m, ls(p));
		if (y > m) s += ask(x, y, m + 1, r, rs(p));
		return s;
	}
}tr;
void dfs1(int x, int f, int d) {
	dep[x] = d;
	si[x] = 1;
	fa[x] = f;
	for (int i = head[x]; i; i = e[i].nx) {
		int to = e[i].v;
		if (to == f) continue;
		dfs1(to, x, d + 1);
		si[x] += si[to];
		if (si[to] > si[son[x]]) son[x] = to;
	}
}
void dfs2(int u, int t) {
	id[u] = ++cnt;
	top[u] = t;
	if (!son[u]) return;
	dfs2(son[u], t);
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (fa[u] == to || to == son[u]) continue;
		dfs2(to, to);
	}
}
int qr(int x, int y) {
	int ans = 0;
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) std::swap(x, y);
		ans += tr.ask(id[top[x]], id[x], 1, n, 1);
		x = fa[top[x]];
	}
	if (dep[x] > dep[y]) std::swap(x, y);
	ans += tr.ask(id[x], id[y], 1, n, 1);
	return ans;
}
void up(int x) {
	tr.upd(id[x], 1, n, 1);
	return;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &x, &y);
		add(x, y);
		add(y, x);
	}
	dfs1(r, 0, 1);
	dfs2(r, r);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		printf("%d\n", qr(r, x));
		up(x);
	}
}