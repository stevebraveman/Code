#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAXN 1010
struct Edge {
	int v, nx, w;
}e[MAXN * MAXN << 2];
int head[MAXN], pre[MAXN], ecnt, n, m, x, y, z, dis[MAXN], ans, t;
bool vis[MAXN], ifmin[MAXN];
void add(int f, int t, int w) {
	e[++ecnt] = (Edge) {t, head[f], w};
	head[f] = ecnt;
}
struct node {
	int id, w;
};
bool operator < (node a, node b) {
	return a.w > b.w;
}
int max(int a, int b) {
	if (a > b) return a;
	else return b;
}
void dijkstra(int s, int u, int v, bool ifrec) {
	memset(vis, 0, sizeof(vis));
	memset(dis, 0x7f, sizeof(dis));
	std::priority_queue <node> q;
	q.push((node) {s, 0});
	dis[s] = 0;
	while (!q.empty()) {
		node f = q.top();
		q.pop();
		int k = f.id;
		if (vis[k]) continue;
		vis[k] = 1;
		for (int i = head[k]; i; i = e[i].nx) {
			int to = e[i].v;
			if ((u == k && v == to) || (to == u && v == k)) continue; 
			if (dis[to] > dis[k] + e[i].w) {
				dis[to] = dis[k] + e[i].w;
				if (ifrec) pre[to] = k;
				q.push((node) {to, dis[to]});
			}
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &x, &y, &z);
		add(x, y, z);
		add(y, x, z);
	}
	dijkstra(n, -1, -1, 1);
	// for (int i = 1; i <= n; i++) {
	// 	printf("%d ", pre[i]);
	// }
	// puts("");
	t = 1;
	while (t != 0) {
		ifmin[t] = 1;
		t = pre[t];
	}
	for (int i = n; i >= 1; i--) {
		if (pre[i] && ifmin[i]) {
			dijkstra(n, pre[i], i, 0);
			// if (dis[n] == 0x7f7f7f7f) {
			// 	continue;
			// }
			ans = max(dis[1], ans);
		}
	}
	printf("%d", ans);
	return 0;
}