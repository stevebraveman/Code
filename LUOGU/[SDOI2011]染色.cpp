#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
void swap(int &x, int &y) {
	int t = x;
	x = y;
	y = t;
}
struct Edge {
	int v, nx;
}e[MAXN << 2];
int head[MAXN], ecnt, n, m, x, y, dep[MAXN], si[MAXN], wt[MAXN], w[MAXN], z;
int fa[MAXN], top[MAXN], son[MAXN], cnt, r = 1, id[MAXN];
char op[5];
void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
struct nd {
	int b, lazy, lc, rc;
}tr[MAXN << 2];
struct Segtree {
	int a[MAXN];
	void pd(int p) {
		tr[p].b = (tr[rs(p)].lc == tr[ls(p)].rc ? -1 : 0) + tr[ls(p)].b + tr[rs(p)].b;
		tr[p].lc = tr[ls(p)].lc;
		tr[p].rc = tr[rs(p)].rc;
	}
	void build(int l, int r, int p) {
		tr[p].lazy = 0;
		if (l == r) {
			tr[p].b = 1;
			tr[p].lc = tr[p].rc = a[l];
			return;
		}
		int m = (l + r) >> 1;
		build(l, m, ls(p));
		build(m + 1, r, rs(p));
		pd(p);
	}
	void f(int l, int r, int k, int p) {
		tr[p].lazy = tr[p].lc = tr[p].rc = k;
		tr[p].b = 1;
	}
	void pushd(int l, int r, int p) {
		if (tr[p].lazy) {
			int m = (l + r) >> 1;
			f(l, m, tr[p].lazy, ls(p));
			f(m + 1, r, tr[p].lazy, rs(p));
			tr[p].lazy = 0;
		}
	}
	void updated(int x, int y, int l, int r, int p, int k) {
		if (x <= l && y >= r) {
			tr[p].b = 1;
			tr[p].lc = tr[p].rc = tr[p].lazy = k;
			return;
		}
		int m = (l + r) >> 1;
		pushd(l, r, p);
		if (x <= m) updated(x, y, l, m, ls(p), k);
		if (y > m) updated(x, y, m + 1, r, rs(p), k);
		pd(p);
	}
	int askp(int x, int l, int r, int p) {
		if (l == r) {
			return tr[p].lc;
		}
		int m = (l + r) >> 1;
		pushd(l, r, p);
		if (x <= m) return askp(x, l, m, ls(p));
		else return askp(x, m + 1, r, rs(p));
	}
	nd ask(int x, int y, int l, int r, int p) {
		if (x <= l && y >= r) {
			return tr[p];
		}
		int m = (l + r) >> 1;
		pushd(l, r, p);
		if(x <= m && y > m) {
			nd a = ask(x, y, l, m, ls(p));
			nd b = ask(x, y, m + 1, r, rs(p));
			nd c;
			c.lc = a.lc;
			c.rc = b.rc;
			c.b = a.b + b.b + (a.rc == b.lc ? -1 : 0);
			return c;
		}
		if (x <= m) return ask(x, y, l, m, ls(p));
		if (y > m) return ask(x, y, m + 1, r, rs(p));
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
inline int query(int x, int y) {
	int ans = 0;
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		nd tot = tree.ask(id[top[x]], id[x], 1, n, 1);
		ans += tot.b;
		ans -= (tree.askp(id[top[x]], 1, n, 1) == tree.askp(id[fa[top[x]]], 1, n, 1));
		x = fa[top[x]];
	}
	if (dep[x] > dep[y]) swap(x, y);
	nd tot = tree.ask(id[x], id[y], 1, n, 1);
	ans += tot.b;
	return ans;
}
inline void change(int x, int y, int k) {
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		tree.updated(id[top[x]], id[x], 1, n, 1, k);
		x = fa[top[x]];
	}
	if (dep[x] > dep[y]) swap(x, y);
	tree.updated(id[x], id[y], 1, n, 1, k);
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
	dfs1(r, -1, 1);
	dfs2(r, r);
	for (int i = 1; i <= n; i++) {
		tree.a[i] = wt[i];
	}
	tree.build(1, n, 1);
	while (m--) {
		scanf("%s", op);
		if (op[0] == 'Q') {
			scanf("%d%d", &x, &y);
			printf("%d\n", query(x, y));
		}
		if (op[0] == 'C') {
			scanf("%d%d%d", &x, &y, &z);
			change(x, y, z);
		}
	}
}