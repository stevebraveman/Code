#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAXN 1001000
#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
#define INF 0x7fffffff
int max(int a, int b) {
	if (a > b) return a;
	else return b;
}
void swap(int &a, int &b) {
	int t = a;
	a = b;
	b = t;
}
struct Edge {
	int f, v, nx, w;
}e[MAXN];
int head[MAXN], ecnt, n, x, y, z, dep[MAXN], son[MAXN], fa[MAXN], wt[MAXN];
int w[MAXN], cnt, top[MAXN], r = 1, id[MAXN], si[MAXN];
struct Segtree {
	int a[MAXN], b[MAXN << 2], tmax[MAXN];
	void pd(int p) {
		b[p] = b[ls(p)] + b[rs(p)];
		tmax[p] = max(tmax[ls(p)], tmax[rs(p)]);
	}
	void build(int p, int l, int r) {
		if (l == r) {
			b[p] = tmax[p] = a[l];
			return;
		}
		int m = (l + r) >> 1;
		build(ls(p), l, m);
		build(rs(p), m + 1, r);
		pd(p);
	}
	void update(int x, int l, int r, int p, int k) {
		if (l == r) {
			b[p] = tmax[p] = k;
			return;
		}
		int m = (l + r) >> 1;
		if (x <= m) update(x, l, m, ls(p), k);
		else update(x, m + 1, r, rs(p), k);
		pd(p);
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
void add(int f, int t, int w) {
	e[++ecnt] = (Edge) {f, t, head[f], w};
	head[f] = ecnt;
}
void dfs1(int u, int f, int deep) {
	dep[u] = deep;
	fa[u] = f;
	si[u] = 1;
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (to == f) continue;
		w[to] = e[i].w;
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
inline int qrm(int x, int y) {
	int ans = -INF;
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		ans = max(ans, tree.qmax(id[top[x]], id[x], 1, n, 1));
		x = fa[top[x]];
	}
	if (dep[x] > dep[y]) swap(x, y);
	ans = max(ans, tree.qmax(id[x] + 1, id[y], 1, n, 1));
	return ans;
}
inline void upd(int x, int k) {
	tree.update(id[x], 1, n, 1, k);
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d%d%d", &x, &y, &z);
		add(x, y, z);
		add(y, x, z);
	}
	dfs1(r, -1, 1);
	dfs2(r, r);
	for (int i = 1; i <= n; i++) {
		tree.a[i] = wt[i];
	}
	tree.build(1, 1, n);
	while (1) {
		char op[10];
		scanf("%s", op);
		if (op[0] == 'Q') {
			scanf("%d%d", &x, &y);
			if (x == y) {
				puts("0");
				continue;
			}
			printf("%d\n", qrm(x, y));
		}
		else if (op[0] == 'C') {
			scanf("%d%d", &x, &y);
			x *= 2;
			if (dep[e[x].f] > dep[e[x].v]) {
				x = e[x].f;
			}
			else {
				x = e[x].v;
			}
			upd(x, y);
		}
		else if (op[0] == 'D') {
			break;
		}
	}
}