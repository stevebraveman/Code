#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define MAXN 1001000
struct Edge {
	int v, nx, w;
}e[MAXN << 2];
int head[MAXN], ecnt, n, m, x, y, dis[MAXN], T;
bool vis[MAXN];
char ele[MAXN];
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
	std::priority_queue <node> q;
	dis[s] = 0;
	q.push((node) {s, 0});
	while (!q.empty()) {
		node v = q.top();
		q.pop();
		int u = v.id;
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
int g(int i, int j) {
	return (i - 1) * (m + 1) + j;
}
int main() {
	memset(head, 0, sizeof(head));
	memset(dis, 0x7f, sizeof(dis));
	ecnt = 0;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%s", ele + 1);
		for (int j = 1; j <= m; j++) {
			if (ele[j] == '/') {
				add(g(i, j), g(i + 1, j + 1), 1);
				add(g(i + 1, j + 1), g(i, j), 1);
				add(g(i + 1, j), g(i, j + 1), 0);
				add(g(i, j + 1), g(i + 1, j), 0);
				
			}
			else {
				add(g(i, j), g(i + 1, j + 1), 0);
				add(g(i + 1, j + 1), g(i, j), 0);
				add(g(i + 1, j), g(i, j + 1), 1);
				add(g(i, j + 1), g(i + 1, j), 1);
			}
		}
	}
	dijkstra(g(1, 1));
	if (dis[g(n + 1, m + 1)] > 2000000000) {
		puts("NO SOLUTION");
		return 0;
	}
	printf("%d\n", dis[g(n + 1, m + 1)]);
}