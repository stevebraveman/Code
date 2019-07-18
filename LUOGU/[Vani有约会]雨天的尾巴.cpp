#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
struct Edge {
	int v, nx;
}e[MAXN << 1];
int head[MAXN], ecnt, n, m, _x, _y, z, x[MAXN], y[MAXN];
int son[MAXN], top[MAXN], fa[MAXN], size[MAXN], dep[MAXN];
int r = 1, id[MAXN], cnt;
void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
void dfs1(int u, int f, int d) {
	fa[u] = f;
	dep[u] = d;
	size[u] = 1;
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (to == f) continue;
		size[u] += size[to];
		if (size[son[u]] < size[to]) son[u] = to;
	}
}
void dfs2(int u, int topf) {
	top[u] = topf;
	id[u] = ++cnt;
	if (!son[u]) return;
	dfs2(son[u], topf);
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (to == fa[u] || to == son[u]) continue;
		dfs2(to, to);
	}
}
void modify(int x, int y) {
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) std::swap(x, y);
		x = fa[top[x]];
	}
	if (dep[x] > dep[y]) std::swap(x, y);
	
	return;
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
		scanf("%d%d", &x[m + 1], &y[m + 1]);
	}
}