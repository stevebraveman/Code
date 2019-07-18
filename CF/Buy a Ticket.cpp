#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAXN 2000010
#define int long long
struct Edge {
	int v, nx, w;
}e[MAXN << 1];
int head[MAXN], ecnt, n, m, x, y, z, dis[MAXN];
bool vis[MAXN], hh;
struct node {
	int id, w;
};
bool operator < (node a, node b) {
	return a.w > b.w;
}
void add(int f, int t, int w) {
	e[++ecnt] = (Edge) {t, head[f], w};
	head[f] = ecnt;
}
void dijkstra(int s) {
	memset(vis, 0, sizeof(vis));
	memset(dis, 0x7f, sizeof(dis));
	dis[s] = 0;
	std::priority_queue <node> q;
	q.push((node) {s, 0});
	while (!q.empty()) {
		node f = q.top();
		q.pop();
		int u = f.id;
		if (vis[u]) continue;
		vis[u] = 1;
		for (int i = head[u]; i; i = e[i].nx) {
			int to = e[i].v;
			if (dis[to] > dis[u] + e[i].w) {
				dis[to] = dis[u] + e[i].w;
				q.push((node) {to, dis[to]});
			}
		}
	}
}
signed main() {
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%lld%lld%lld", &x, &y, &z);
		add(x, y, z * 2);
		add(y, x, z * 2);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &x);
		add(n + 1, i, x);
		add(i, n + 1, x);
	}
	dijkstra(n + 1);
	for (int i = 1; i <= n; i++) {
		printf("%lld ", dis[i]);
	}
	return 0;
}