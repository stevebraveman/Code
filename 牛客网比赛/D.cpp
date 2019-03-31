#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>
#define MAXN 50005
#define INF 0x7fffffffffLL
#define int long long
int dis[MAXN], vis[MAXN], ecnt, n, m, u, head[MAXN];
struct Edge{
	int v, nx, w;
}e[MAXN * 4];
struct node{
	int id, w;
};
bool operator < (node a, node b) {
	return a.w > b.w;
}
void add(int from, int to, int weight) {
	e[++ecnt] = (Edge){to, head[from], weight};
	head[from] = ecnt;
}
void dijkstra(int s) {
	for (int i = 1; i <= n; i++) {
		dis[i] = INF;
	}
	memset(vis, 0, sizeof (vis));
	std::priority_queue <node> q;
	dis[s] = 0;
	q.push((node){s, 0});
	while (!q.empty()) {
		node f = q.top();
		q.pop();
		int v = f.id;
		if (vis[v]) continue;
		vis[v] = 1;
		for (int i = head[v]; i; i = e[i].nx) {
			int to = e[i].v;
			if (dis[to] > dis[v] + e[i].w) {
				dis[to] = dis[v] + e[i].w;
				q.push((node){to, dis[to]});
			}
		}
	}
}
int op, t;
signed main() {
	scanf("%lld%lld%lld%lld", &n, &m, &u, &t);
	for (int i = 1; i <= m; i++) {
		int x, y, z;
		scanf("");
		scanf("%lld%lld%lld%lld", &op, &x, &y, &z);
		if (op == 0) continue;
		add(x , y , z);
		add(y , x , z);
	}
	dijkstra(u);
	if (dis[t] == INF) {
		puts("My gold!!!");
		return 0;
	}
	printf("%d" , dis[t]);
}