#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 500100
struct Edge {
	int v, nx, w;
}e[MAXN << 1];
int head[MAXN], ecnt, n, m, x, y, z, dis[MAXN], f[MAXN];
long long ans;
void add(int f, int t, int w) {
	e[++ecnt] = (Edge) {t, head[f], w};
	head[f] = ecnt;
}
void dfs1(int u, int fa) {
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (to == fa) continue;
		dfs1(to, u);
		dis[u] = std::max(dis[u], dis[to] + e[i].w);
	}
}
void dfs2(int u, int fa) {
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (to == fa) continue;
		ans += 1LL * (dis[u] - (dis[to] + e[i].w));
		dfs2(to, u);
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i < n; i++) {
		scanf("%d%d%d", &x, &y, &z);
		add(x, y, z);
		add(y, x, z);
	}
	dfs1(m, 0);
	dfs2(m, 0);
	printf("%lld", ans);
}