#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 500010
#define LOG 19
struct Edge {
	int v, nx, w;
}e[MAXN << 1];
int dep[MAXN], anc[MAXN][LOG + 1], n, m, x, y, z, dis[MAXN], head[MAXN], ecnt, d[MAXN];
void add(int f, int t, int w) {
	e[++ecnt] = (Edge) {t, head[f], w};
	head[f] = ecnt;
}
void dfs(int u, int f, int d) {
	dep[u] = d;
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (to == f) continue;
		anc[to][0] = u;
		dis[to] = dis[u] + e[i].w;
		dfs(to, u, d + 1);
	}
}
void dfs2(int u, int f) {
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (to == f) continue;
		dfs2(to, u);
		dis2[u] = std::max(dis2[to] + e[i].w, dis2[u]);
	}
}
void dfs3(int u, int f) {
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (to == f) continue;
		dfs3(to, u);
		dis
	}
}
void swim(int &x, int h) {
	for (int i = 0; h; i++) {
		if (h & 1) x = anc[x][i];
		h >>= 1;
	}
}
int LCA(int x, int y) {
	if (dep[x] < dep[y]) std::swap(x, y);
	swim(x, dep[x] - dep[y]);
	if (x == y) return x;
	for (int i = LOG; i >= 0; i--) {
		if (anc[x][i] != anc[y][i]) {
			x = anc[x][i];
			y = anc[y][i];
		}
	}
	return anc[x][0];
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i < n; i++) {
		scanf("%d%d%d", &x, &y, &z);
		add(x, y, z);
		add(y, x, z);
	}
	dfs(1, 0, 1);
	dfs2(1, 0);
	for (int i = 1; i <= LOG; i++) {
		for (int j = 1; j <= n; j++) {
			anc[j][i] = anc[anc[j][i - 1]][i - 1];
		}
	}
	while (m--) {
		scanf("%d%d", &x, &y);
		printf("%d %d\n", LCA(x, y), dis[x] + dis[y] - 2 * dis[LCA(x, y)] + dis2[x] + dis2[y]);
	}
}
/*
4 4
1 2 1
1 3 1

 */