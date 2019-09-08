#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#define clear(x) memset((x), 0, sizeof(x))
#define MAXN 200100
struct Edge {
	int v, nx, w;
}e[MAXN];
int head[MAXN], ecnt, n, m, f[MAXN][55], x[MAXN], y[MAXN], z[MAXN];
int dis[MAXN], T, p, k, st[MAXN][55], ans;
bool vis[MAXN];
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
void dijkstra(int s) {
	memset(dis, 0x7f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
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
int dfs(int u, int d) {
	if (st[u][d]) return -1;
	if (f[u][d]) return f[u][d];
	st[u][d] = 1;
	f[u][d] = (u == n) ? 1 : 0;
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		int w = dis[to] - dis[u] + e[i].w;
		if (w <= d) {
			int tot = dfs(to, d - w);
			if (tot == -1) return f[u][d] = -1;
			f[u][d] += tot;
			f[u][d] %= p;
		}
	}
	st[u][d] = 0;
	return f[u][d];
}
int main() {
	scanf("%d", &T);
	while (T--) {
		clear(e);
		clear(head);
		ecnt = 0;
		clear(x), clear(y), clear(z);
		clear(f);
		clear(st);
		scanf("%d%d%d%d", &n, &m, &k, &p);
		for (int i = 1; i <= m; i++) {
			scanf("%d%d%d", &x[i], &y[i], &z[i]);
			add(y[i], x[i], z[i]);
		}
		dijkstra(n);
		clear(head);
		clear(e);
		ecnt = 0;
		for (int i = 1; i <= m; i++) {
			add(x[i], y[i], z[i]);
		}
		ans = dfs(1, k);
		printf("%d\n", ans);
	}
}