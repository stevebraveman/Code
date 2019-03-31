#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAXN 1001000
#define iNF 2000000000
#define int long long
struct Edge {
	int v, nx, w;
}e[MAXN], e1[MAXN];
int head[MAXN], ecnt = 1, n, m, x, y, dep[MAXN], cur[MAXN], r, k, co[MAXN], z;
int he[MAXN], ec = 1, dis[MAXN];
bool vis[MAXN];
void add_w(int f, int t, int w) {
	e1[++ec] = (Edge) {t, he[f], w};
	he[f] = ec;
}
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
void add(int f, int t, int w) {
	e[++ecnt] = (Edge) {t, head[f], w};
	head[f] = ecnt;
	e[++ecnt] = (Edge) {f, head[t], 0};
	head[t] = ecnt;
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
		int v = f.id;
		q.pop();
		if (vis[v]) continue;
		vis[v] = 1;
		for (int i = he[v]; i; i = e1[i].nx) {
			int to = e1[i].v;
			if (dis[to] > dis[v] + e1[i].w) {
				dis[to] = dis[v] + e1[i].w;
				q.push((node) {to, dis[to]});
			}
		}
	}
}
std::queue <int> q;
bool bfs(int s, int t) {
	memset(dep, 0x7f, sizeof(dep));
	dep[s] = 0;
	while (!q.empty()) q.pop();
	q.push(s);
	for (int i = 1; i <= n * 2; i++) {
		cur[i] = head[i];
	}
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = head[u]; i; i = e[i].nx) {
			int to = e[i].v;
			if (dep[to] > iNF && e[i].w) {
				dep[to] = dep[u] + 1;
				q.push(to);
			}
		}
	}
	if (dep[t] > iNF) return 0;
	else return 1;
}
int dfs(int s, int t, int l) {
	if (!l || s == t) return l;
	int fl = 0, f = 0;
	for (int i = cur[s]; i; i = e[i].nx) {
		cur[s] = i;
		int to = e[i].v;
		if (dep[to] == dep[s] + 1 && (f = dfs(to, t, min(l, e[i].w)))) {
			fl += f;
			l -= f;
			e[i].w -= f;
			e[i ^ 1].w += f;
			if (!l) break;
		}
	}
	return fl;
}
int Dinic(int s, int t) {
	int maxf = 0;
	while (bfs(s, t)) {
		maxf += dfs(s, t, iNF);
	}
	return maxf;
}
signed main() {
	scanf("%lld%lld", &n, &m);
	r = 1, k = n * 2;
	for (int i = 1; i <= m; i++) {
		scanf("%lld%lld%lld", &x, &y, &z);
		add_w(x, y, z);
		add_w(y, x, z);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &co[i]);
		if (i != 1 && i != n) {
			add(i + n, i, co[i]);
		}
		else {
			add(i + n, i, iNF);
		}
	}
	dijkstra(1);
	for (int i = 1; i <= n; i++) {
		for (int j = he[i]; j; j = e1[j].nx) {
			int to = e1[j].v;
			if (dis[to] == dis[i] + e1[j].w) {
				add(i, to + n, iNF);
			}
		}
	}
	printf("%lld", Dinic(r, k));
}