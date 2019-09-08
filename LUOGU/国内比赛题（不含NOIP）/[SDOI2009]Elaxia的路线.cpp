#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define full(x) memset((x), 0x7f, sizeof(x))
#define MAXN 1010000
struct Edge {
	int v, nx, w;
}e[MAXN << 2];
int ans, head[MAXN], ecnt, n, f[MAXN], m, x[MAXN], y[MAXN], z[MAXN], dis[MAXN], dis2[MAXN], _dis[MAXN], _dis2[MAXN], x1, y1, x2, y2;
bool vis[MAXN], use[MAXN];
void add(int f, int t, int w) {
	e[++ecnt] = (Edge) {t, head[f], w};
	head[f] = ecnt;
}
void spfa(int s, int *dis) {
	memset(vis, 0, sizeof(vis));
	dis[s] = 0;
	std::queue <int> q;
	q.push(s);
	vis[s] = 1;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = 0;
		for (int i = head[u]; i; i = e[i].nx) {
			int to = e[i].v;
			if (dis[to] > dis[u] + e[i].w) {
				dis[to] = dis[u] + e[i].w;
				if (!vis[to]) {
					vis[to] = 1;
					q.push(to);
				}
			}
		}
	}
}
int dfs(int u) {
	if (f[u]) return f[u];
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		f[u] = std::max(f[u], dfs(to) + e[i].w);
	}
	return f[u];
}
int main() {
	scanf("%d%d%d%d%d%d", &n, &m, &x1, &x2, &y1, &y2);
	full(dis);
	full(dis2);
	full(_dis);
	full(_dis2);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &x[i], &y[i], &z[i]);
		add(x[i], y[i], z[i]);
		add(y[i], x[i], z[i]);
	}
	spfa(x1, dis);
	spfa(y1, dis2);
	spfa(x2, _dis);
	spfa(y2, _dis2);
	// memset(x, 0, sizeof(x));
	// memset(y, 0, sizeof(y));
	// memset(z, 0, sizeof(z));
	memset(head, 0, sizeof(head));
	ecnt = 0;
	for (int i = 1; i <= m; i++) {
		if (dis[x[i]] + z[i] + _dis[y[i]] == dis[x2]) {
			if (dis2[x[i]] + _dis2[y[i]] + z[i] == dis2[y2]) add(x[i], y[i], z[i]), use[x[i]] = use[y[i]] = 1;
			if (dis2[y[i]] + _dis2[x[i]] + z[i] == dis2[y2]) add(y[i], x[i], z[i]), use[x[i]] = use[y[i]] = 1;
		}
		if (dis[y[i]] + z[i] + _dis[x[i]] == dis[x2]) {
			if (dis2[x[i]] + _dis2[y[i]] + z[i] == dis2[y2]) add(x[i], y[i], z[i]), use[x[i]] = use[y[i]] = 1;
			if (dis2[y[i]] + _dis2[x[i]] + z[i] == dis2[y2]) add(y[i], x[i], z[i]), use[x[i]] = use[y[i]] = 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (use[i] && !f[i]) dfs(i);
	}
	// puts("OK");
	// for (int i = 1; i <= m; i++) {
	// 	if (use[i]) printf("%d\n", i);
	// }
	for (int i = 1; i <= n; i++) {
		ans = std::max(ans, f[i]);
	}
	printf("%d\n", ans);
}