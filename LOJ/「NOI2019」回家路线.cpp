#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <queue>
#define MAXN 100010
struct Edge {
	int v, nx, st, ed;
}e[MAXN << 1];
int head[MAXN], ecnt, n, m, x, y, z, _z, dis[1010][MAXN], A, B, C, ans = 0x7fffffff;
bool vis[1010][MAXN];
void add(int f, int t, int s, int en) {
	e[++ecnt] = (Edge) {t, head[f], s, en};
	head[f] = ecnt;
}
struct node {
	int id, w, t;
};
bool operator < (node a, node b) {
	return a.w > b.w;
}
void dijkstra(int s) {
	memset(dis, 0x7f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	dis[0][s] = 0;
	std::priority_queue <node> q;
	q.push((node) {s, 0, 0});
	while (!q.empty()) {
		node f = q.top();
		q.pop();
		int u = f.id;
		int tim = f.t;
		if (vis[tim][u]) continue;
		vis[tim][u] = 1;
		for (int i = head[u]; i; i = e[i].nx) {
			if (e[i].st < tim) continue;
			int to = e[i].v;
			int w = e[i].st - tim;
			if (dis[e[i].ed][to] > dis[tim][u] + A * w * w + B * w + C + (to == n ? e[i].ed : 0)) {
				dis[e[i].ed][to] = dis[tim][u] + A * w * w + B * w + C + (to == n ? e[i].ed : 0);
				q.push((node) {to, dis[e[i].ed][to], e[i].ed});
			}
		}
	}
}
void spfa(int s) {
	memset(dis, 0x7f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	dis[0][s] = 0;
	vis[0][s] = 1;
	std::queue <int> q1;
	std::queue <int> q2;
	q1.push(s);
	q2.push(0);
	while (!q1.empty()) {
		int u = q1.front();
		q1.pop();
		int tim = q2.front();
		q2.pop();
		vis[tim][u] = 0;
		for (int i = head[u]; i; i = e[i].nx) {
			if (e[i].st < tim) continue;
			int to = e[i].v;
			int w = e[i].st - tim;
			if (dis[e[i].ed][to] > dis[tim][u] + A * w * w + B * w + C + (to == n ? e[i].ed : 0)) {
				dis[e[i].ed][to] = dis[tim][u] + A * w * w + B * w + C + (to == n ? e[i].ed : 0);
				if (!vis[e[i].ed][to]) {
					vis[e[i].ed][to] = 1;
					q1.push(to);
					q2.push(e[i].ed);
				}
			}
		}
	}
}
int main() {
#ifdef ONLINE_JUDGE
	freopen("route.in", "r", stdin);
	freopen("route.out", "w", stdout);
#endif
	scanf("%d%d%d%d%d", &n, &m, &A, &B, &C);
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d%d", &x, &y, &z, &_z);
		add(x, y, z, _z);
	}
	dijkstra(1);
	for (int i = 1; i <= m; i++) {
		if (e[i].v == n) ans = std::min(dis[e[i].ed][n], ans);
	}
	printf("%d", ans);
	return 0;
}