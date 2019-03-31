#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#define MAXN 100010
struct Edge {
	int v, nx, w;
}e[MAXN << 2];
int head[MAXN], ecnt, n, m, x, y, siz[MAXN], son[MAXN], minn, r, dis[MAXN], ans, size, tots, z, tot, k;
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
int solve(int u, int val) {
	tot = 0;
	int l = 1;
	int s = 0;
	dfsdis(u, 0, val);
	std::sort(dis + 1, dis + 1 + tot);
	while (l < tot) {
		if (dis[l] + dis[tot] <= k) s += tot - l, l++;
		else tot--;
	}
	return s;
}
void divide(int u) {
	vis[u] = 1;
	ans += solve(u, 0);
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (vis[to]) continue;
		ans -= solve(to, e[i].w);
		size = siz[to];
		r = 0;
		dfs(to, 0);
		divide(r);
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		scanf("%d%d%d", &x, &y, &z);
		add(x, y, z);
		add(y, x, z);
	}
	scanf("%d", &k);
	size = son[0] = n;
	dfs(1, 0);
	divide(r);
	printf("%d\n", ans);
	return 0;
}