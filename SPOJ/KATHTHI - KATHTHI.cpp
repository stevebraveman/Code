#pragma GCC optimize(2)
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define MAXN 1100
char g[MAXN][MAXN];
struct Edge {
	int v, nx, w;
}e[MAXN * MAXN << 2];
int head[MAXN * MAXN << 2], n, m, ecnt, x, y, dis[MAXN * MAXN << 2], T;
bool vis[MAXN * MAXN << 2];
void add(int f, int t, int w) {
	e[++ecnt] = (Edge) {t, head[f], w};
	head[f] = ecnt;
}
void spfa(int s) {
	memset(dis, 0x7f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	std::queue <int> q;
	q.push(s);
	dis[s] = 0;
	vis[s] = 1;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = 0;
		for (int i = head[u]; i; i = e[i].nx) {
			int to = e[i].v;
			if (dis[to] > dis[u] + e[i].w) {
				dis[to] = dis[u] + e[i].w;
				if (!vis[to]) {
					vis[to] = 1;
					q.push(to);
				}
			}
		}
	}
}
int ph(int i, int j) {
	return (i - 1) * m + j;
}
int main() {
	scanf("%d", &T);
	while (T--) {
		memset(head, 0, sizeof(head));
		ecnt = 0;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) {
			scanf("%s", g[i] + 1);
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (i < n) {
					if (g[i][j] == g[i + 1][j]) add(ph(i, j), ph(i + 1, j), 0);
					else add(ph(i, j), ph(i + 1, j), 1);
				}
				if (i > 1) {
					if (g[i][j] == g[i - 1][j]) add(ph(i, j), ph(i - 1, j), 0);
					else add(ph(i, j), ph(i - 1, j), 1);
				}
				if (j > 1) {
					if (g[i][j] == g[i][j - 1]) add(ph(i, j), ph(i, j - 1), 0);
					else add(ph(i, j), ph(i, j - 1), 1);
				}
				if (j < m) {
					if (g[i][j] == g[i][j + 1]) add(ph(i, j), ph(i, j + 1), 0);
					else add(ph(i, j), ph(i, j + 1), 1);
				}
			}
		}
		spfa(ph(1, 1));
		printf("%d\n", dis[ph(n, m)]);
	}
	
}