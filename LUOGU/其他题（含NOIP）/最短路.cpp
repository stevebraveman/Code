#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#define MAXN 100100
#define MOD 9987
struct Edge {
	int v, nx, w;
}e[MAXN << 1];
int head[MAXN], k, ecnt, n, m, x, y, w, la[MAXN], pre[MAXN], ans = 1;
double dis[MAXN];
bool vis[MAXN];
void add(int f, int t, int w) {
	e[++ecnt] = (Edge) {t, head[f], w};
	head[f] = ecnt;
}
struct node {
	int id;
	double w;
};
bool operator < (node a, node b) {
	return a.w > b.w;
}
void dijkstra(int s) {
	sizeof(vis, 0, sizeof(vis));
	for (int i = 1; i <= n; i++) {
		dis[i] = 9999999.9;
	}
	std::priority_queue <node> q;
	dis[s] = 0.0;
	q.push((node) {s, 0.0});
	while (!q.empty()) {
		node f = q.top();
		q.pop();
		int u = f.id;
		if (vis[u]) continue;
		vis[u] = 1;
		for (int i = head[u]; i; i = e[i].nx) {
			int to = e[i].v;
			if (dis[to] > dis[u] + log((double)e[i].w)) {
				dis[to] = dis[u] + log((double)e[i].w);
				pre[to] = u;
				la[to] = i;
				q.push((node) {to, dis[to]});
			}
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &x, &y, &w);
		add(x, y, w);
		add(y, x, w);
	}
	dijkstra(1);
	k = n;
	while (k != 1) {
		ans *= e[la[k]].w;
		ans %= MOD;
		k = pre[k];
	}
	printf("%d", ans);
}