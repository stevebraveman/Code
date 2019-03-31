#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1000110
#define il inline
#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
struct Edge {
	int v, nx;
}e[MAXN * 4];
int head[MAXN << 2], ecnt, n, m, x, y, cnt, wt[MAXN], w[MAXN], op, l, r, k;
int dep[MAXN], fa[MAXN], son[MAXN], si[MAXN], id[MAXN], top[MAXN];
void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
struct Segtree {
	int a[MAXN], b[MAXN << 2];
	inline void pd(int p) {
		b[p] = b[rs(p)] ^ b[ls(p)];
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
	void update(int x, int l , int r , int p , int k) {
		if (l == r) {
			b[p] = k;
			return;
		}
		int m = (l + r) >> 1;
		if (x <= m) update(x, l , m, ls(p), k);
		else update(x, m + 1, r, rs(p), k);
		pd(p);
	}
	int sum(int x, int y, int l, int r, int p) {
		int s = 0;
		if (x <= l && y >= r) {
			return b[p];
		}
		int m = (l + r) >> 1;
		if (x <= m) s ^= sum(x, y, l, m, ls(p));
		if (y > m) s ^= sum(x, y, m + 1, r, rs(p));
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
inline int qr(int x, int y) {
	int ans = 0;
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) std::swap(x, y);
		ans ^= tree.sum(id[top[x]], id[x], 1, n, 1);
		x = fa[top[x]];
	}
	if (dep[x] > dep[y]) std::swap(x, y);
	ans ^= tree.sum(id[x], id[y], 1, n, 1);
	return ans;
}
inline void ups(int x, int k) {
	tree.update(id[x], 1, n, 1, k);
}
char s[5];
int main() {
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &w[i]);
	}
	for (int i = 1; i < n; i++) {
		scanf("%lld%lld", &x, &y);
		add(x, y);
		add(y, x);
	}
	r = 1;
	dfs1(r, -1, 1);
	dfs2(r, r);
	for (int i = 1; i <= n; i++) {
		tree.a[i] = wt[i];
	}
	tree.build(1, n, 1);
	scanf("%d", &m);
	while (m--) {
		scanf("%s", s);
		if (s[0] == 'Q') {
			scanf("%lld%lld", &l, &r);
			puts(qr(l, r) ? "Yes" : "No");
		}
		else {
			scanf("%lld%lld", &l, &r);
			ups(l, r);
		}
	}
}