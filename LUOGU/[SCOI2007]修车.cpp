#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define MAXN 100010
struct Edge {
	int v, nx, fl, w;
}e[MAXN];
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
int n, m, s, t, head[MAXN], dis[MAXN], ecnt = 1, flow[MAXN];
int maxf, minc, la[MAXN], pre[MAXN], x, y, z, f, G[250][250];
bool vis[MAXN];
std::queue <int> q;
void add(int f, int t, int fl, int w) {
	e[++ecnt] = (Edge) {t, head[f], fl, w};
	head[f] = ecnt;
	e[++ecnt] = (Edge) {f, head[t], 0, -w};
	head[t] = ecnt;
}
bool spfa(int s, int t) {
	memset(dis, 0x7f, sizeof(dis));
	memset(flow, 0x7f, sizeof(flow));
	memset(vis, 0, sizeof(vis));
	pre[t] = -1;
	dis[s] = 0;
	vis[s] = 1;
	q.push(s);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		vis[v] = 0;
		for (int i = head[v]; i; i = e[i].nx) {
			int f = e[i].fl;
			int to = e[i].v;
			if (f > 0 && dis[to] > dis[v] + e[i].w) {
				dis[to] = dis[v] + e[i].w;
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
			e[k].fl -= flow[t];
			e[k ^ 1].fl += flow[t];
			v = pre[v];
		}
	}
}
int main() {
	scanf("%d%d", &m, &n);
	s = 2 * n * m + 1;
	t = s + 1;
	for (int i = 1; i <= n * m; i++) {
		add(s, i, 1, 0);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &G[i][j]);
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			for (int p = 1; p <= n; p++) {
				add((i - 1) * n + p, j + n * m, 1, G[j][i] * p);
			}
		}
	}
	for (int i = 1; i <= n * m; i++) {
		add(i + n * m, t, 1, 0);
	}
	mcmf(s, t);
	printf("%.2f\n", (double)minc / n);
	return 0;
}