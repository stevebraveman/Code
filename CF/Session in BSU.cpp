#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define MAXN 100100
struct Edge {
	int v, nx;
}e[MAXN << 2];
int swap(int &a, int &b) {
	int t = a;
	a = b;
	b = t;
}
int head[MAXN], siz[MAXN], ecnt, n, m, x[MAXN], y[MAXN], fa[MAXN], dis[MAXN], dep[MAXN], son[MAXN], top[MAXN], r = 1, _x, _y;
void add(int f, int t) {
	e[++ecnt] = (Edge) {t, head[f]};
	head[f] = ecnt;
}
void dfs1(int u, int f, int d) {
	dep[u] = d;
	fa[u] = f;
	siz[u] = 1;
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (to == f) continue;
		dfs1(to, u, d + 1);
		siz[u] += siz[to];
		if (siz[to] > siz[son[u]]) son[u] = to;
	}
}
void dfs2(int u, int topf) {
	top[u] = topf;
	if (!son[u]) return;
	dfs2(son[u], topf);
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (to == fa[u] || to == son[u]) continue;
		dfs2(to, to);
	}
}
int LCA(int a, int b) {
	while (top[a] != top[b]) {
		if (dep[top[a]] < dep[top[b]]) swap(a, b);
		a = fa[top[a]];
	}
	if (dep[a] > dep[b]) swap(a, b);
	return a;
}
void dfs(int u, int f) {
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (to == f) continue;
		dfs(to, u);
		dis[u] += dis[to];
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &x[i], &y[i]);
		add(x[i], y[i]);
		add(y[i], x[i]);
	}
	dfs1(r, 0, 1);
	dfs2(r, r);
	scanf("%d", &m);
	while (m--) {
		scanf("%d%d", &_x, &_y);
		int lca = LCA(_x, _y);
		dis[_x]++;
		dis[_y]++;
		dis[lca] -= 2;
	}
	dfs(r, 0);
	for (int i = 1; i < n; i++) {
		if (dep[x[i]] > dep[y[i]]) {
			printf("%d\n", dis[x[i]]);
		}
		else {
			printf("%d\n", dis[y[i]]);
		}
	}
}