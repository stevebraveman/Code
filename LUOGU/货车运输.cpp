#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
#define INF 0x7fffffff
#define MAXN 11000
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
struct Edge {
	int v, nx, w;
}e[MAXN << 3];
int head[MAXN], ecnt, n, m, x, y, dep[MAXN], si[MAXN], wt[MAXN], w[MAXN];
int f[MAXN], fa[MAXN], top[MAXN], son[MAXN], cnt, r = 1, id[MAXN];
void add(int f, int t, int w) {
	e[++ecnt] = (Edge) {t, head[f], w};
	head[f] = ecnt;
}
struct Segtree {
	int a[MAXN], tmin[MAXN << 2];
	void pd(int p) {
		tmin[p] = min(tmin[ls(p)], tmin[rs(p)]);
	}
	void build(int l, int r, int p) {
		if (l == r) {
			tmin[p] = a[l];
			return;
		}
		int m = (l + r) >> 1;
		build(l, m, ls(p));
		build(m + 1, r, rs(p));
		pd(p);
	}
	int qmax(int x, int y, int l, int r, int p) {
		int s = INF;
		if (x <= l && y >= r) {
			return tmin[p];
		}
		int m = (l + r) >> 1;
		if (x <= m) s = min(qmax(x, y, l, m, ls(p)), s);
		if (y > m) s = min(qmax(x, y, m + 1, r, rs(p)), s);
		return s;
	}
}tree;
void dfs1(int u, int fat, int deep) {
	dep[u] = deep;
	fa[u] = fat;
	si[u] = 1;
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (to == fat) continue;
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
	int ans = INF;
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) std::swap(x, y);
		ans = min(tree.qmax(id[top[x]], id[x], 1, n, 1), ans);
		x = fa[top[x]];
	}
	if (dep[x] > dep[y]) std::swap(x, y);
	ans = min(tree.qmax(id[x] + 1, id[y], 1, n, 1), ans);
	return ans;
}
struct E {
	int u, v, w;
	bool is;
}ee[MAXN << 3];
int find(int x) {
	if (f[x] == x) return x;
	else return f[x] = find(f[x]);
}
bool cmp(E a, E b) {
	return a.w > b.w;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &ee[i].u, &ee[i].v, &ee[i].w);
	}
	for (int i = 1; i <= n; i++) {
		f[i] = i;
	}
	std::sort(ee + 1, ee + 1 + m, cmp);
	for (int i = 1; i <= m; i++) {
		if (find(ee[i].u) == find(ee[i].v)) continue;
		// printf("%d %d\n", find(ee[i].u), find(ee[i].v));
		// printf("%d --- %d\n", ee[i].u, ee[i].v);
		f[find(ee[i].u)] = find(ee[i].v);
		ee[i].is = 1;
	}
	for (int i = 1; i <= m; i++) {
		if (ee[i].is) add(ee[i].u, ee[i].v, ee[i].w), add(ee[i].v, ee[i].u, ee[i].w);
	}
	memset(wt, 0x7f, sizeof(wt));
	for (int i = 1; i <= n; i++) {
		if (dep[i]) continue;
		// puts("OK");
		dfs1(i, 0, 1);
		dfs2(i, i);
	}
	for (int i = 1; i <= n; i++) {
		tree.a[i] = wt[i];
	}
	tree.build(1, n, 1);
	int q;
	scanf("%d", &q);
	while (q--) {
		scanf("%d%d", &x, &y);
		if (find(x) != find(y)) {
			puts("-1");
			continue;
		}
		printf("%d\n", qrm(x, y));
	}
	return 0;
}
/*
5 7
4 3 4440
3 1 22348
1 3 28368
2 4 25086
5 3 6991
4 3 10638
3 1 11106
4
4 5
1 3
5 4
2 5
*/