#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAXN 100010
#define INF 100000007
struct Edge {
	int v, nx, w;
}e[MAXN << 2];
int head[MAXN], ecnt, n, m, x, y, z, k, dis1[MAXN], dis2[MAXN], num[MAXN], ans = INF, G[5010][5010];
bool vis[MAXN], cant[MAXN];
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
void dijkstra(int s, int t) {
	memset(vis, 0, sizeof(vis));
	dis1[s] = 0;
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
			if (dis1[to] > dis1[u] + e[i].w && !cant[to]) {
				dis1[to] = dis1[u] + e[i].w;
				q.push((node) {to, dis1[to]});
			}
		}
	}
	memset(vis, 0, sizeof(vis));
	dis2[t] = 0;
	q.push((node) {t, 0});
	while (!q.empty()) {
		node f = q.top();
		q.pop();
		int u = f.id;
		if (vis[u]) continue;
		vis[u] = 1;
		for (int i = head[u]; i; i = e[i].nx) {
			int to = e[i].v;
			if (dis2[to] > dis2[u] + e[i].w && !cant[to]) {
				dis2[to] = dis2[u] + e[i].w;
				q.push((node) {to, dis2[to]});
			}
		}
	}
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &x, &y, &z);
		add(x, y, z);
		add(y, x, z);
	}
	for (int i = 2; i < n; i++) {
		for (int j = head[i]; j; j = e[j].nx) {
			int to = e[j].v;
			if (!vis[to]) {
				vis[to] = 1;
				num[i]++;
			}
		}
		for (int j = head[i]; j; j = e[j].nx) {
			int to = e[j].v;
			vis[to] = 0;
		}
	}
	for (int i = 2; i < n; i++) {
		if (num[i] < k) cant[i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		dis1[i] = dis2[i] = INF;
	}
	dijkstra(1, n);
	for (int i = 1; i <= n; i++) {
		if (cant[i]) continue;
		for (int j = head[i]; j; j = e[j].nx) {
			int to = e[j].v;
			if (cant[to]) continue;
			if (dis1[i] + e[j].w + dis2[to] < ans && dis1[i] + e[j].w + dis2[to] > dis1[n]) {
				ans = dis1[i] + e[j].w + dis2[to];
			}
		}
	}
	printf("%d\n", ans >= INF ? -1 : ans);
	return 0;
}