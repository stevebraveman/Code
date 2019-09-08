#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <queue>
#define MAXN 1000010
#define INF 2000000000
struct Edge {
	int v, nx, w, c;
}e[MAXN << 2];
int head[MAXN], b[MAXN], ecnt = 1, nc, n, m, x, y, z;
int pre[MAXN], maxf, minc, dis[MAXN], la[MAXN], flow[MAXN], r, k, tot;
bool vis[MAXN];
template <typename Tp>
Tp min(Tp a, Tp b) {
	if (a < b) return a;
	else return b;
}
void add(int f, int t, int w, int c) {
	e[++ecnt] = (Edge) {t, head[f], w, c};
	head[f] = ecnt;
	e[++ecnt] = (Edge) {f, head[t], 0, -c};
	head[t] = ecnt;
}
bool spfa(int s, int t) {
	memset(dis, 0x7f, sizeof(dis));
	memset(flow, 0x7f, sizeof(flow));
	memset(vis, 0, sizeof(vis));
	pre[t] = -1;
	dis[s] = 0;
	vis[s] = 1;
	std::queue <int> q;
	q.push(s);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		vis[v] = 0;
		for (int i = head[v]; i; i = e[i].nx) {
			int f = e[i].w;
			int to = e[i].v;
			if (f > 0 && dis[to] > dis[v] + e[i].c) {
				dis[to] = dis[v] + e[i].c;
				pre[to] = v;
				la[to] = i;
				flow[to] = min(flow[v], f);
				if (!vis[to]) {
					vis[to] = 1;
					q.push(to);
				}
			}
		}
	}
	return pre[t] != -1;
}
void mcmf(int s, int t) {
	while (spfa(s, t)) {
		int v = t;
		maxf += flow[t];
		minc += flow[t] * dis[t];
		while (v != s) {
			int k = la[v];
			e[k].w -= flow[t];
			e[k ^ 1].w += flow[t];
			v = pre[v];
		}
	}
}
int g(int i, int j) {
	return (i - 1) * m + j;
}
void dfs(int car, int u) {
	if (u == g(n, m) + n * m) return;
	for (int i = head[u]; i; i = e[i].nx) {
		int to = e[i].v;
		if (e[i ^ 1].w && u < to + n * m) {
			e[i ^ 1].w--;
			printf("%d %d\n", car, (n * m - (u - to)) == 1);
			return dfs(car, to + n * m);
		}
	}
}
int main() {
	scanf("%d%d%d", &nc, &m, &n);
	r = n * m * 2 + 1;
	k = r + 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &x);
			if (x == 1) continue;
			add(g(i, j), g(i, j) + n * m, INF, 0);
			if (x == 2) {
				add(g(i, j), g(i, j) + n * m, 1, -1);
			}
			if (i > 1) add(g(i - 1, j) + n * m, g(i, j), INF, 0);
			if (j > 1) add(g(i, j - 1) + n * m, g(i, j), INF, 0);
		}
	}
	add(r, g(1, 1), nc, 0);
	add(g(n, m) + n * m, k, nc, 0);
	mcmf(r, k);
	for (int i = 1; i <= nc; i++) {
		dfs(i, g(1, 1) + n * m);
	}
	return 0;
}