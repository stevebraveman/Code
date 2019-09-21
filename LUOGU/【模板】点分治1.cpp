#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#define MAXN 100010
struct Edge {
	int v, nx, w;
}e[MAXN << 2];
int head[MAXN], ecnt, n, m, x, y, siz[MAXN], son[MAXN], minn, r, dis[MAXN], ans[MAXN * 100], size, totsiz, z, tot;
bool vis[MAXN];
void add(int f, int t, int w) {
	e[++ecnt] = (Edge) {t, head[f], w};
	head[f] = ecnt;
}
int max(int a, int b) {
	if (a > b) return a;
	else return b;
}
void dfs(int u, int fa) {
	siz[u] = 1;
	son[u] = 0;
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (vis[to] || to == fa) continue;
		dfs(to, u);
		siz[u] += siz[to];
		son[u] = max(son[u], siz[to]);
	}
	son[u] = max(son[u], size - siz[u]);
	if (son[r] > son[u]) r = u;
}
void dfsdis(int u, int fa, int len) {
	dis[++tot] = len;
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (vis[to] || to == fa) continue;
		dfsdis(to, u, len + e[i].w);
	}
}
void solve(int u, int val, int op) {
	tot = 0;
	dfsdis(u, 0, val);
	for (int i = 1; i <= tot; i++) {
		for (int j = 1; j <= tot; j++) {
			ans[dis[i] + dis[j]] += op;
		}
	}
}
void divide(int u) {
	vis[u] = 1;
	solve(u, 0, 1);
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (vis[to]) continue;
		solve(to, e[i].w, -1);
		size = siz[to];
		r = 0;
		dfs(to, 0);
		divide(r);
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i < n; i++) {
		scanf("%d%d%d", &x, &y, &z);
		add(x, y, z);
		add(y, x, z);
	}
	size = son[0] = n;
	dfs(1, 0);
	divide(r);
	while (m--) {
		scanf("%d", &x);
		puts(ans[x] ? "AYE" : "NAY");
	}
	return 0;
}
/*
7 9
1 2 13
1 3 15
1 4 16
4 5 12
5 6 18
4 7 5
34
7
30
45
49
31
10
10
45
 */