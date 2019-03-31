#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define MAXN 100010
#define INF 2000000000
struct Edge {
	int v, nx, fl, w;
}e[MAXN];
int n, m, r, k, head[MAXN], dis[MAXN], ecnt = 1, flow[MAXN], maxf, minc, la[MAXN], pre[MAXN], x, y, z, f, mp[60][60];
bool vis[MAXN];
std::queue <int> q;
int min(int a, int b) {
	if (a < b) return a;
	else return b;
}
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
	q.push(s);
	dis[s] = 0;
	vis[s] = 1;
	pre[t] = -1;
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
int g(int i, int j) {
	return (i - 1) * n + j;
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
	scanf("%d%d", &n, &m);
	r = 2 * n * n + 1;
	k = 2 * n * n + 2;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &mp[i][j]);
		}
	}
	add(r, g(1, 1), m, 0);
	add(g(n, n) + n * n, k, m, 0);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			add(g(i, j), g(i, j) + n * n, 1, -mp[i][j]);
			add(g(i, j), g(i, j) + n * n, INF, 0);
			if (i < n) {
				add(g(i, j) + n * n, g(i + 1, j), INF, 0);
			}
			if (j < n) {
				add(g(i, j) + n * n, g(i, j + 1), INF, 0);
			}
		}
	}
	mcmf(r, k);
	printf("%d\n", -minc);
	return 0;
}