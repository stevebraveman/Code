#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <queue>
#define MAXN 1000010
struct Edge {
	int v, nx, w1, w2, an;
}e[MAXN << 2], _e[MAXN << 2];
int head[MAXN], ecnt, n, m, x, y, a, b, dis1[MAXN], dis2[MAXN], idis1[MAXN], idis2[MAXN], _head[MAXN], _ec;
bool vis[MAXN];
struct node {
	int id, w;
};
bool operator < (node a, node b) {
	return a.w > b.w;
}
void add(int f, int t, int p, int q) {
	e[++ecnt] = (Edge) {t, head[f], p, q, 0};
	head[f] = ecnt;
	_e[++_ec] = (Edge) {f, _head[t], p, q, 0};
	_head[t] = _ec;
}
void init() {
	memset(dis1, 0x7f, sizeof(dis1));
	memset(dis2, 0x7f, sizeof(dis2));
	memset(idis1, 0x7f, sizeof(idis1));
	memset(idis2, 0x7f, sizeof(idis2));
}
void dijkstra3(int s, int dis[]) {
	memset(vis, 0, sizeof(vis));
	std::priority_queue <node> q;
	q.push((node) {s, 0});
	dis[s] = 0;
	while (!q.empty()) {
		node f = q.top();
		q.pop();
		int u = f.id;
		if (vis[u]) continue;
		vis[u] = 1;
		for (int i = _head[u]; i; i = _e[i].nx) {
			int to = _e[i].v;
			if (dis[to] > dis[u] + _e[i].w1) {
				dis[to] = dis[u] + _e[i].w1;
				q.push((node) {to, dis[to]});
			}
		}
	}
}
void dijkstra4(int s, int dis[]) {
	memset(vis, 0, sizeof(vis));
	std::priority_queue <node> q;
	q.push((node) {s, 0});
	dis[s] = 0;
	while (!q.empty()) {
		node f = q.top();
		q.pop();
		int u = f.id;
		if (vis[u]) continue;
		vis[u] = 1;
		for (int i = _head[u]; i; i = _e[i].nx) {
			int to = _e[i].v;
			if (dis[to] > dis[u] + _e[i].w2) {
				dis[to] = dis[u] + _e[i].w2;
				q.push((node) {to, dis[to]});
			}
		}
	}
}
int dis[MAXN];
void spfa(int s) {
	memset(dis, 0x7f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	std::queue <int> q;
	dis[s] = 0;
	vis[s] = 1;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = 0;
		for (int i = head[u]; i; i = e[i].nx) {
			int to = e[i].v;
			if (dis[to] > dis[u] + e[i].an) {
				dis[to] = dis[u] + e[i].an;
				if (!vis[to]) {
					vis[to] = 1;
					q.push(to);
				}
			}
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d%d", &x, &y, &a, &b);
		add(x, y, a, b);
	}
	init();
	dijkstra3(n, idis1);
	dijkstra4(n, idis2);
	for (int i = 1; i <= n; i++) {
		for (int j = head[i]; j; j = e[j].nx) {
			int to = e[j].v;
			if (idis1[to] + e[j].w1 != idis1[i]) {
				e[j].an++;
			}
			if (idis2[to] + e[j].w2 != idis2[i]) {
				e[j].an++;
			}
		}
	}
	spfa(1);
	printf("%d\n", dis[n]);
	return 0;
}