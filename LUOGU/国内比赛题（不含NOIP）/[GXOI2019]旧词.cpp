#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 100010
struct Edge {
	int v, nx;
}e[MAXN << 2];
int head[MAXN], ecnt, n, m, k, x, y, q;
int size[MAXN], son[MAXN], dep[MAXN], top[MAXN], fa[MAXN], r = 1;
void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
void dfs1(int u, int f, int d) {
	dep[u] = d;
	fa[u] = f;
	size[u] = 1;
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (to == f) continue;
		dfs1(to, u, d + 1);
		size[u] += size[to];
		if (size[to] > size[son[u]]) son[u] = to;
	}
}
void dfs2(int u, int topf) {
	top[u] = topf;
	if (!son[u]) return;
	dfs2(son[u], topf);
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (to == son[u] || to == fa[u]) continue;
		dfs2(to, to);
	}
}
int LCA(int x, int y) {
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) std::swap(x, y);
		x = fa[top[x]];
	}
	if (dep[x] > dep[y]) std::swap(x, y);
	return x;
}
int solve(int x, int y) {

}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i < n; i++) {
		scanf("%d", &x);
		add(i, x);
		add(x, i);
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &x, &y);
	}
}