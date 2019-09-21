#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAXN 5000100
struct Edge {
	int v, nx, w;
}e[MAXN];
int head[MAXN], ecnt, n, m, x, y, tx, ty, dis[MAXN];
char mp[510][510];
bool vis[MAXN];
void add(int f, int t, int w) {
	e[++ecnt] = (Edge) {t, head[f], w};
	head[f] = ecnt;
}
int g(int i, int j) {
	return (i - 1) * m + j;
}
struct node {
	int id, w;
};
bool operator < (node a, node b) {
	return a.w > b.w;
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
		vis[u] = 0;
		for (int i = head[u]; i; i = e[i].nx) {
			int to = e[i].v;
			if (dis[to] > dis[u] + e[i].w) {
				dis[to] = dis[u] + e[i].w;
				q.push((node) {to, dis[to]});
			}
		}
	}
}
int main() {
	while (true) {
		scanf("%d%d", &n, &m);
		if (n == 0 || m == 0) break;
		for (int i = 1; i <= n; i++) {
			scanf("%s", mp[i] + 1);
		}
		memset(head, 0, sizeof(head));
		ecnt = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (i > 1) add(g(i, j), g(i - 1, j), mp[i][j] != mp[i - 1][j]);
				if (i < n) add(g(i, j), g(i + 1, j), mp[i][j] != mp[i + 1][j]);
				if (j > 1) add(g(i, j), g(i, j - 1), mp[i][j] != mp[i][j - 1]);
				if (j < m) add(g(i, j), g(i, j + 1), mp[i][j] != mp[i][j + 1]);
			}
		}
		scanf("%d%d%d%d", &x, &y, &tx, &ty);
		x++, y++, tx++, ty++;
		dijkstra(g(x, y));
		printf("%d\n", dis[g(tx, ty)]);
	}
}