#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#define MAXN 1001000
template <typename Tp>
Tp min(Tp a, Tp b) {
	if (a < b) return a;
	else return b;
}
struct Edge {
	int v, nx, w, c;
}e[MAXN << 2];
int head[MAXN], ecnt = 1, n, m, x, y, dis[MAXN], flow[MAXN], pre[MAXN];
int la[MAXN], maxf, minc, z, c, r, k, g[20][20], cnt;
bool vis[MAXN];
char a[20][20];
void add(int f, int t, int w, int c) {
	e[++ecnt] = (Edge) {t, head[f], w, c};
	head[f] = ecnt;
	e[++ecnt] = (Edge) {f, head[t], 0, -c};
	head[t] = ecnt;
}
bool spfa(int s, int t) {
	memset(dis, 0x7f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	memset(flow, 0x7f, sizeof(flow));
	pre[t] = -1;
	dis[s] = 0;
	std::queue <int> q;
	q.push(s);
	vis[s] = 1;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = 0;
		for (int i = head[u]; i; i = e[i].nx) {
			int to = e[i].v;
			if (dis[to] > dis[u] + e[i].c && e[i].w) {
				dis[to] = dis[u] + e[i].c;
				pre[to] = u;
				la[to] = i;
				flow[to] = min(flow[u], e[i].w);
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
		maxf += flow[t];
		minc += flow[t] * dis[t];
		int v = t;
		while (v != s) {
			int k = la[v];
			e[k].w -= flow[t];
			e[k ^ 1].w += flow[t];
			v = pre[v];
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	r = 2 * n * m + 1;
	k = r + 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			std::cin >> a[i][j];
			g[i][j] = ++cnt;
		}
	}
	for (int i = 1; i <= n * m; i++) {
		add(r, i, 1, 0);
		add(i + n * m, k, 1, 0);
	}
	for (int i = 1; i <= m; i++) {
		g[0][i] = g[n][i];
		g[n + 1][i] = g[1][i];
	}
	for (int i = 1; i <= n; i++) {
		g[i][0] = g[i][m];
		g[i][m + 1] = g[i][1];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] == 'U') add(g[i][j], g[i - 1][j] + n * m, 1, 0);
			else add(g[i][j], g[i - 1][j] + n * m, 1, 1);
			if (a[i][j] == 'D') add(g[i][j], g[i + 1][j] + n * m, 1, 0);
			else add(g[i][j], g[i + 1][j] + n * m, 1, 1);
			if (a[i][j] == 'L') add(g[i][j], g[i][j - 1] + n * m, 1, 0);
			else add(g[i][j], g[i][j - 1] + n * m, 1, 1);
			if (a[i][j] == 'R') add(g[i][j], g[i][j + 1] + n * m, 1, 0);
			else add(g[i][j], g[i][j + 1] + n * m, 1, 1);
		}
	}
	// puts("OK");
	mcmf(r, k);
	printf("%d", minc);
	return 0;
}