#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
#define INF 0x7fffffff
#define MAXN 500100
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
}e[MAXN << 2];
int head[MAXN], ecnt, n, m, x, y, dep[MAXN], si[MAXN], wt[MAXN], w[MAXN];
int fa[MAXN], top[MAXN], son[MAXN], cnt, r = 1, id[MAXN];
char op[5];
void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
struct Segtree {
	int a[MAXN], b[MAXN << 2], lazy[MAXN << 2];
	void pd(int p) {
		b[p] = b[ls(p)] + b[rs(p)];
	}
	void f(int l, int r, int p, int k) {
		b[p] += (r - l + 1) * k;
		lazy[p] += k;
	}
	void pushd(int l, int r, int p) {
		if (lazy[p]) {
			int m = (l + r) >> 1;
			f(l, m, ls(p), lazy[p]);
			f(m + 1, r, rs(p), lazy[p]);
			lazy[p] = 0;
		}
	}
	void update(int x, int y, int l, int r, int p, int k) {
		if (x <= l && y >= r) {
			b[p] += (r - l + 1) * k;
			lazy[p] += k;
			return;
		}
		int m = (l + r) >> 1;
		pushd(l, r, p);
		if (x <= m) update(x, y, l, m, ls(p), k);
		if (y > m) update(x, y, m + 1, r, rs(p), k);
		pd(p);
	}
	int ask(int x, int y, int l, int r, int p) {
		int s = 0;
		if (x <= l && y >= r) {
			return b[p];
		}
		int m = (l + r) >> 1;
		pushd(l, r, p);
		if (x <= m) s += ask(x, y, l, m, ls(p));
		if (y > m) s += ask(x, y, m + 1, r, rs(p));
		return s;
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
	int ans = 0;
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		ans += tr.ask(id[top[x]], id[x], 1, n, 1);
		x = fa[top[x]];
	}
	if (dep[x] > dep[y]) swap(x, y);
	ans += tr.ask(id[x] + 1, id[y], 1, n, 1);
	return ans;
}
inline void up(int x, int y) {
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		tr.update(id[top[x]], id[x], 1, n, 1, 1);
		x = fa[top[x]];
	}
	if (dep[x] > dep[y]) swap(x, y);
	tr.update(id[x] + 1, id[y], 1, n, 1, 1);
	return;
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
	while (m--) {
		scanf("%s%d%d", op, &x, &y);
		if (op[0] == 'P') {
			up(x, y);
		}
		else {
			printf("%d\n", qrm(x, y));
		}
	}
}